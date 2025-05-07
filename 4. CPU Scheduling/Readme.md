# 🖥️ CPU Scheduling Algorithms Simulator

## 📌 Problem Statement

Write a program to simulate the following CPU Scheduling Algorithms:

- 🔷 First-Come, First-Served (FCFS)
- 🟨 Shortest Job First (SJF) – Preemptive
- 🟧 Priority Scheduling – Non-Preemptive
- 🟩 Round Robin (RR) – Preemptive

---

## 🎯 Objective

To understand and implement fundamental CPU scheduling strategies and analyze their behavior based on different scheduling criteria such as arrival time, burst time, priority, and time quantum.

---

## 🧠 Algorithms Overview

### 🔷 FCFS (First-Come, First-Served)
- Processes are executed in the order they arrive.
- Non-preemptive and easy to implement.

### 🟨 SJF (Shortest Job First – Preemptive)
- The process with the shortest remaining time is selected next.
- Also known as Shortest Remaining Time First (SRTF).
- Preemptive in nature.

### 🟧 Priority Scheduling (Non-Preemptive)
- Each process is assigned a priority.
- The process with the highest priority (lowest number) is executed next.

### 🟩 Round Robin (Preemptive)
- Each process is assigned a fixed time quantum.
- After the quantum, the process is preempted and added to the end of the queue.

---

## 🛠️ Features

- Accepts process details like arrival time, burst time, and priority.
- Allows input of time quantum for Round Robin.
- Displays Gantt Chart, Waiting Time, Turnaround Time for each process.
- Calculates average waiting time and average turnaround time.

---

## 🧰 Requirements

- Language: Python / C / C++ / Java
- CLI or GUI-based input/output
- Basic data structures like arrays, queues, and sorting logic

---

## 📈 Sample Output (Expected)

- ✅ Process execution order (Gantt Chart)
- 📊 Turnaround Time and Waiting Time for each process
- 📉 Average Turnaround Time and Average Waiting Time

---

## 🚀 Future Enhancements

- Add GUI support for better visualization
- Support for multi-core CPU simulation
- Graphical Gantt chart generation

---

## 📄 License

Open-source project created for academic purposes 🎓. Free to use and modify.
