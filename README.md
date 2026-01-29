# 🏦 BankSys OOP

A high-performance **Bank Management System** built with **C++**. Focused on clean **OOP** architecture, advanced data security, and a rich visual experience.

---

## 🎨 Immersive UI
* **Full Color Support:** A completely colored interface for better readability.
* **Dynamic Permissions:** Menu options change colors based on user access levels.
* **Modern Dashboards:** Data is presented in clean, colored tables and headers.

---

## 🛡️ Advanced Security
* **5-Layer Encryption:** Custom engine implemented as: 
  `XOR Cipher → Random Padding → Case Inversion → Nested XOR → Hex Conversion`.
* **Audit Trail:** Every user action is logged with a timestamp for security monitoring.
* **Refresh Security:** Option to re-encrypt all passwords periodically.
* **Permissions Control:** Granular access management for each module.

---

## 🚀 Key Features
* **Client Management:** Full CRUD operations (Add, Find, Update, Delete).
* **Transactions:** Secure Deposit, Withdraw, and Transfer with real-time validation.
* **Data Persistence:** Encrypted storage using File Handling (`fstream`).
* **Input Validation:** Robust sanitization to prevent crashes.

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
