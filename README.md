# DataStructure-Implementation
Some data structure Implementation using C++

This pragram is implemented using a queue data structure to handle the commands management. These are the steps to ensure a correct 
CPU stimulation.

1. Block Running process: Move what's in Running Queue to tail of Blocked Queue, place head of Read Queue into the Rinning Queue
 
2. Preempt Running Queue process: Move  what's in Runing Queue Queue to tail of Ready Queue, place head of Read  Queue Running Queue

3. Unblock a blocked process: Move head of Blocked Queue to tail to tail of Running Queue
 
4. Terminate the Running Process: Remove what's in the Running  Queue; place  head of Ready Queue into Running Queue

5. Start a new Process: Create a new process at the tail of  the Ready Queue 
