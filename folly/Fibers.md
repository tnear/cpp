# Fibers

`folly::fibers` is an async C++ framework, which uses fibers for parallelism.

## Threading model
- Multiple fibers can be running on top of a single system thread
- Context switching between fibers is very fast (200 million per second per core)
- Each fiber has a stack of fixed size

### FiberManager
Fiber creation and scheduling is performed by `FiberManager`. FiberManager is not thread-safe. One instance of FiberManager should be created per thread.

## Example
This example uses **one** thread to create and execute two tasks.
```cpp
folly::EventBase evb;
auto &fiberManager = folly::fibers::getFiberManager(evb);
folly::fibers::Baton baton;

fiberManager.addTask([&]() {
    cout << "Task 1: start" << endl;
    baton.wait();
    cout << "Task 1: after baton.wait()" << endl;
});

fiberManager.addTask([&]() {
    cout << "Task 2: start" << endl;
    baton.post();
    cout << "Task 2: after baton.post()" << endl;
});

evb.loop();
```

This prints (on the same thread):
```
Task 1: start
Task 2: start
Task 2: after baton.post()
Task 1: after baton.wait()
```

## Synchronization primitives
Synchronization primitives supported by fibers include `Baton` (shown in example above), `await`, `collectN`, and `TimedMutex`. All of these are built using `Baton`.

### Baton
`fibers::Baton` is the core synchronization primitive used to suspend a fiber-task and notify when the task can be resumed.

`wait()` will suspend the current fiber-task until `post()` is called on the same Baton.

## Limitations
- Each fiber uses a preallocated stack. This means that many fibers requires a large amount of memory.

## Resources
- https://github.com/facebook/folly/blob/main/folly/fibers/README.md