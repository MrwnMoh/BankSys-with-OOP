# 🏦 BankSys OOP

A high-performance **Bank Management System** built with **C++**. Focused on clean **OOP** architecture, advanced data security, and a rich visual experience.

---

## 🚀 Key Features (User Journey)

* **Secure Login System:** The entry point of the system. A robust authentication gateway that verifies user credentials before granting access.
* **Colored Permission Indicators:** After login, the main menu displays dynamic markers next to options. These change color (Green/Red) to show accessible features based on the user's specific permissions.
* **Client Management:** Full CRUD operations (Add, Find, Update, Delete) with persistent and encrypted storage.
* **Transactions Module:** Secure banking operations including Deposit, Withdraw, and Transfer with real-time balance validation.
* **Currency Exchange System:** A complete module to view live-style rates relative to USD, search for currencies, and perform instant conversions.
* **User Activity Tracking & Viewer:** A sophisticated system that records every move (Login, Transactions, Client edits). Includes an **Admin Log Viewer** to audit these records in a clean, formatted table.
* **Permissions Management & Display:** A dedicated interface for users to view their access levels and for admins to manage them.
* **Data Persistence:** All records (Clients, Users, Logs) are securely saved using C++ File Handling (`fstream`).
* **Input Validation:** A robust sanitization layer that prevents system crashes by validating every user entry.

---

## 🎨 Immersive UI
* **Full Color Support:** A professional, color-coded terminal interface that makes the console look modern and readable.
* **Modern Terminal Dashboards:** Data is organized in clean, formatted tables with colored headers for a premium feel.

---

## 🛡️ Advanced Security
* **5-Layer Encryption:** A custom cryptographic engine that secures data through: 
  `XOR Cipher → Random Padding → Case Inversion → Nested XOR → Hex Conversion`.
* **Refresh Security Tool:** A unique feature to re-encrypt all user passwords in the system files periodically to ensure maximum protection.
* **Audit Trail:** Comprehensive logging of all system interactions to ensure accountability.

---

## 🔐 Encryption Walkthrough (Example)

| Step | Transformation Level | Result / Status |
| :--- | :--- | :--- |
| 0 | **Original Text** | `Hello World!` |
| 1 | **XOR Encryption** | Applied with Key: `Marwan` |
| 2 | **Random Padding** | Data obfuscated with random noise |
| 3 | **Case Inversion** | Letter casing flipped for complexity |
| 4 | **Nested XOR** | Second security pass applied |
| 5 | **Hexadecimal** | `3D101A1A000221051405170D4865...` |

---

## 💻 Technical Logic
```cpp
// Custom 5-layer encryption implemented:
string Encrypted = _EncryptText(_InvertTextCase(_AddRandomPadding(_EncryptText(Text, Key), Key)), Key);
return TextToHex(Encrypted);
