# 🧾 Two-Pass Assembler for a Pseudo-Machine

## 📌 Problem Statement

Design suitable data structures and implement **Pass 1** and **Pass 2** of a two-pass assembler for a pseudo-machine.  
The implementation should include:
- A few instructions from each category (Imperative, Declarative, and Assembler Directives).
- Generation of:
  - 🗂️ Intermediate Code File
  - 🧮 Symbol Table

The output of **Pass 1** (Intermediate Code and Symbol Table) will serve as input to **Pass 2** for final machine code generation.

---

## 🎯 Objectives

- Understand the structure and functioning of a two-pass assembler.
- Implement appropriate data structures (Symbol Table, Literal Table, etc.).
- Translate assembly language into machine code in two separate passes.
- Support basic pseudo-instructions and directives.

---

## ⚙️ Key Features

### ✅ Pass 1
- Scans source code line-by-line.
- Builds:
  - **Symbol Table** (labels and addresses)
  - **Literal Table** (if implemented)
  - **Pool Table** (for managing literals)
- Generates **Intermediate Code** with placeholders for addresses.

### ✅ Pass 2
- Resolves all addresses using the Symbol Table.
- Generates final **Machine Code**.
- Handles forward references using the Intermediate Code.

---

## 🗃️ Data Structures

- **Symbol Table**: Stores symbols (labels, variables) and their addresses.
- **Opcode Table**: Maps mnemonics to opcode numbers and instruction formats.
- **Literal Table** *(optional)*: Stores literals used in the program.
- **Intermediate Code List**: Stores partially translated instructions.
- **Pool Table** *(optional)*: Manages groups of literals.

---

## 🖥️ Supported Instructions (Sample Set)

### 🔹 Imperative Statements
- `MOV`, `ADD`, `SUB`, `MUL`, `DIV`, etc.

### 🔸 Declarative Statements
- `DS` (Define Storage), `DC` (Define Constant)

### 🟪 Assembler Directives
- `START`, `END`, `ORIGIN`, `EQU`, `LTORG`

---

## 📄 Input/Output

### ✍️ Input
- Assembly source code with labels, mnemonics, and directives.

### 🗂️ Output of Pass 1
- Intermediate Code
- Symbol Table (with symbols and their addresses)

### 📤 Output of Pass 2
- Final machine-level code with resolved addresses and operands.

---

## 📈 Sample Output Files

- `intermediate.txt`
- `symbol_table.txt`
- `machine_code.txt`

---

## 🔧 Tools & Technologies

- Language: C / C++ / Python / Java
- Text files for input/output
- CLI-based interface for interaction

---

## 🚀 Future Enhancements

- Add literal support with LTORG and Pool Table
- Error handling and syntax validation
- Graphical representation of tables and code flow

---

## 📄 License

Educational project created for compiler design and systems programming coursework. Free to use and extend 🚀.
