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
  `Cipher → Padding → Case Inversion → Nested Key → Hex`.
* **Audit Trail:** Every user action is logged with a timestamp for security monitoring.
* **Refresh Security:** Option to re-encrypt all passwords periodically.
* **Permissions Control:** Granular access management for each module.

---

## 🚀 Key Features
* **Client Management:** Full CRUD operations (Add, Find, Update, Delete).
* **Transactions:** Secure Deposit, Withdraw, and Transfer with real-time validation.
* **Data Persistence:** Encrypted storage using File Handling (`fstream`).
* **Input Validation:** Robust sanitization to prevent crashes and ensure data integrity.

---

## 💻 Technical Logic (Encryption)
```cpp
// Custom 5-layer encryption logic:
string Encrypted = _EncryptText(_InvertTextCase(_AddRandomPadding(_EncryptText(Text, Key), Key)), Key);
return TextToHex(Encrypted);
