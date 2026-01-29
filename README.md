# 🏦 BankSys OOP

A high-performance **Bank Management System** built with **C++**. Focused on clean **OOP** architecture, advanced data security, and a rich visual experience.

---

## 🚀 Key Features
* **Currency Exchange System:** A complete module to view exchange rates relative to the USD, search for specific currencies, and perform instant conversions between any two currencies.
* **Permissions Management & Display:** A dedicated system to view and manage user access levels. Users can see their authorized modules clearly within the system.
* **Client Management:** Full CRUD operations (Add, Find, Update, Delete) with persistent storage.
* **Transactions Module:** Secure Deposit, Withdraw, and Transfer operations with real-time validation.
* **Data Persistence:** Ensures all bank records, logs, and user data are securely saved using file handling.
* **Input Validation:** Prevents invalid entries and system crashes with robust sanitization.
* **Menu-based Console Navigation:** Intuitive navigation throughout the entire system.

---

## 🎨 Immersive UI & Smart Navigation
* **Colored Permission Indicators:** The main menu features dynamic markers (icons) next to each option. These markers change color based on the user's permissions, letting you know if you have access before even clicking.
* **Full Color Support:** A completely colored interface for better readability and a professional look.
* **Modern Terminal Dashboards:** Data is presented in clean, colored tables and headers for clear visualization.

---

## 🛡️ Advanced Security
* **5-Layer Encryption:** Custom engine implemented as: 
  `XOR Cipher → Random Padding → Case Inversion → Nested XOR → Hex Conversion`.
* **Audit Trail:** Every user action is logged with a timestamp for security monitoring.
* **Refresh Security:** Option to re-encrypt all passwords periodically to maintain high-level protection.
* **Permissions Control:** Granular access management for each module (Admin/User).

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
