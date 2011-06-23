Vision thread is a helper library for Qt based computer vision applications.

Vision thread implements video input, processing and computer vision tasks in a separate thread from Qt GUI, while
keeping the code for creation the vision subsystem and communication with it as simple and straightforward as possible.

# The first attempt

A single VideoThread object runs a separate thread which polls video input for frames, wraps frame data into
QImage and makes it available (for processing and display) via a Qt signal. The idea is that processing objects will be
created inside the video thread and use direct signal->slot connections, while main thread (and possibly other threads,
e.g. robot hardware control threads) will use queued signal->slot connections.

This works, but care must be taken to use queued connections between vision / GUI threads. Automatic connections don't
work because VideoThread itself "lives" (in strict Qt sense) in the main thread.

A better, safer solution with simpler external API would have video objects (input/processing) separated from the
thread object and living in the vision thread in some more obvious way. Something along the lines of the sugestions
form [this thread](http://lists.trolltech.com/qt-interest/2007-09/thread00073-0.html)

# A second attempt

VideoCapture object moves itself to a different thread upon construction. The thread itself is supplied by the client
code. All connections between the GUI objects and VideoCapture can be automatic.

Another helper object - ThreadWaiter - quits registered threads when the application is about to quit and waits for
them to finish.

The main() looks like a bit of a highly coupled boilerplate mess though.
