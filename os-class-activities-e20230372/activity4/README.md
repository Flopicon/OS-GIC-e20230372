# Class Activity 4 — Shared File API: C++ Mutex & Java `synchronized`

## Student Information

- **Student Name:** Hour Samnang
- **Student ID:** e20230372
- **Partner:** Meylorng (e20230260)
- **Server IP:** 10.78.199.136
- **Operating System:** Ubuntu WSL


## 1. Objective

The objective of this activity is to understand race conditions when multiple clients request updates to a shared file. We compare the behavior of C++ without and with a mutex, and Java without and with the `synchronized` keyword.

## 2. Experiment Results

| Experiment | Port | Expected Score | Actual Score | Result |
|---|---|---|---|---|
| C++ Before Mutex | 9001 | 20 | 2 | Race condition |
| C++ After Mutex | 9002 | 20 | 20 | Correct |
| Java Before `synchronized` | 9011 | 20 | 1 | Race condition |
| Java After `synchronized` | 9012 | 20 | 20 | Correct |

Each student sent 10 requests, for a total of 20 requests.

### Task 1 — C++ Before Mutex

Without a mutex, multiple threads accessed `shared_score.txt` at the same time. Several threads read the same score and overwrote each other's updates.

The expected score was 20, but the actual score was 2.

**Evidence:** `screenshots/cpp_before_mutex.png`

### Task 2 — C++ After Mutex

We used `std::mutex` and `std::lock_guard<std::mutex>` to protect the read-modify-write operation.

The final score was 20, showing that all requests were counted correctly.

**Evidence:** `screenshots/cpp_after_mutex.png`

### Task 3 — Java Before `synchronized`

Without synchronization, multiple Java threads read and updated the shared file concurrently.

The expected score was 20, but the actual score was 1 because updates were lost.

**Evidence:** `screenshots/java_before_synchronized.png`

### Task 4 — Java After `synchronized`

We added the `synchronized` keyword to the `updateScore()` method, allowing only one thread at a time to execute the method.

The final score was 20, showing that all requests were counted correctly.

**Evidence:** `screenshots/java_after_synchronized.png`

## 3. Questions and Answers

### Q1. Why do clients send requests to the server instead of writing the shared file directly?

The server manages access to the shared file. This allows the server to control updates and apply synchronization. If clients wrote directly to the file, they could overwrite each other's changes.

### Q2. Why can a race condition still happen on the server without mutex or synchronization?

The server creates multiple threads to handle client requests. These threads can access the same file at the same time. Without synchronization, multiple threads may read the same old value and overwrite one another's updates.

### Q3. What does `std::lock_guard<std::mutex>` protect in C++?

It protects the critical section that reads, increments, and writes the shared score. It locks the mutex when entering the section and automatically unlocks it when leaving the scope.

### Q4. What does Java `synchronized` protect?

It prevents multiple threads from executing the synchronized method simultaneously on the same lock. In our program, it protects the shared score update operation.

### Q5. Why is the expected final score 20?

Two students each send 10 increment requests. Every request should increase the score by 1, starting from 0.

Therefore, 10 + 10 = 20.

### Q6. What happens if two separate servers update the same file simultaneously?

A C++ mutex or Java `synchronized` method only coordinates threads using the same lock within one process. Two separate server processes do not share that lock, so race conditions may still happen. Cross-process file locking or another shared coordination mechanism would be required.

## 4. Reflection

This activity demonstrated how race conditions can cause lost updates when multiple threads access shared data concurrently.

In the C++ experiment, the score increased from 2 without a mutex to 20 with a mutex.

In the Java experiment, the score increased from 1 without synchronization to 20 with `synchronized`.

We learned that synchronization is important for protecting critical sections and maintaining data consistency in multithreaded applications.
