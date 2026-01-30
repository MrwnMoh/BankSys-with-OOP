# 🏦 Bank Management System (OOP)

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Solutions-blue?style=for-the-badge&logo=c%2B%2B" alt="C++">
  <img src="https://img.shields.io/badge/Object--Oriented-Programming-green?style=for-the-badge" alt="OOP">
  <img src="https://img.shields.io/badge/Security-5--Layer%20Encryption-red?style=for-the-badge" alt="Security">
  <!-- Animated badges -->
  <img src="https://img.shields.io/badge/Code-Fast-FC6600?style=for-the-badge&logo=appveyor&labelColor=1F1F1F&animation=spin" alt="Fast Coding">
  <img src="https://img.shields.io/badge/Debugging-Master-yellow?style=for-the-badge&logo=travis&labelColor=1F1F1F&animation=pulse" alt="Debugging">
</p>

---

## 📝 Introduction
A high-performance **Console-based Bank Management System** built with **C++**. This project focuses on **Object-Oriented Programming (OOP)** principles, providing a secure and visually intuitive way to manage banking operations, currency exchange, and user activities.

---

## 🚀 Main Features

### 🔐 1. Authentication & Access
- **Secure Login System:** The gateway to the system with credential verification.
- **Dynamic Permissions:** Each user has specific access rights (Admin/User).
- **Colored Status Indicators:** Visual markers that change color based on permissions before you even click.

### 👥 2. Client & User Management
- **Client Operations:** Full CRUD (Add, Delete, Update, Find) with encrypted storage.
- **User Operations:** Complete management of system users and their security levels.
- **Permissions Display:** A dedicated screen to view what each user is allowed to do.

### 💰 3. Banking & Transactions
- **Balance Management:** Deposit, Withdraw, and Total Balances.
- **Transfer System:** Secure money transfer between accounts with real-time validation.
- **Transfer Logs:** Recording all financial movements between clients for auditing.

### 🌍 4. Currency Exchange System
- **Live-Style Rates:** View currency rates relative to the USD.
- **Currency Finder:** Search for any currency by code or country.
- **Currency Calculator:** Perform instant conversions between different global currencies.

### 🛡️ 5. Security & Logs (Audit Trail)
- **User Move Tracking:** The system records every single action by the user (Login, Edits, Views).
- **Logs Viewer:** A clean, formatted table for admins to review all system activities (Login Logs & Transfer Logs).
- **Security Refresh:** A tool to re-encrypt data files to ensure maximum protection.

---

## 🎨 User Interface (UI)
- **Full Color Support:** A professional color-coded terminal experience for better UX.
- **Modular Menus:** Intuitive navigation through nested, organized screens.
- **Formatted Tables:** Data is displayed in neat, structured, and colored tables.

---

## 🔐 Encryption Engine (5-Layers)
The system protects sensitive data using a custom-built cryptographic logic:
1. **XOR Cipher** (Initial encryption)
2. **Random Padding** (Noise injection)
3. **Case Inversion** (Casing flip)
4. **Nested XOR** (Double security)
5. **Hexadecimal** (Final storage format)

---

## 📂 Project Structure (Layered Architecture)

| Layer | Responsibility | Key Files |
| :--- | :--- | :--- |
| **Core** | Business Logic & Models | `clsBankClient.h`, `clsUser.h`, `clsCurrency.h` |
| **Libs** | Logic Utilities & Security | `clsCrypt.h`, `clsInputValidation.h`, `clsUtility.h` |
| **Screens** | UI: Management & Logic | `clsLoginScreen.h`, `clsMainScreen.h`, `clsScreen.h` |
| **Screens/Bank** | Client UI Operations | `clsAddNewClientScreen.h`, `clsClientListScreen.h` |
| **Screens/Curr** | Currency UI Operations | `clsCurrencyExhangeScreen.h`, `clsCalculationScreen.h` |
| **Screens/Trans** | Financial UI Operations | `clsDepositScreen.h`, `clsTransfareScreen.h` |
| **Screens/Logs** | Auditing UI Operations | `clsSystemLogsScreen.h`, `clsTransferLogsScreen.h` |

---

## 🛠 Tools & Technologies
- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **Key Concepts:** Encapsulation, Inheritance, Polymorphism, Abstraction, File Handling.

---

## 👨‍💻 Author
**Marwan**
> "Building secure and scalable software solutions."
