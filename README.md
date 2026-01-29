# BankSys OOP 🏦

A high-performance console-based **Bank Management System** developed using **C++**. This project showcases the practical application of **Object-Oriented Programming (OOP)** with a specialized focus on **Advanced Data Security**, **User Authorization**, and a **Rich Visual Experience**.

---

## 🎨 Immersive User Interface (Full Color Support)

Unlike standard black-and-white console apps, this system features a **Full Color-Coded Interface** to enhance usability and aesthetics:

* **Dynamic Permissions Rendering:** The main menu intelligently changes colors to indicate which features are accessible or locked based on your permission level.
* **Status Indicators:** Success messages, errors, and warnings are distinctively colored (Green/Red/Yellow) for instant visual feedback.
* **Modern Terminal Dashboard:** Every screen is designed as a modular dashboard, using colored headers and formatted tables to organize client data clearly.

---

## 🛡️ Exclusive Security & User Control

* **5-Layer Encryption Engine:** A custom cryptographic process (Key Cipher, Padding, Case Inversion, Nested Encryption, and Hex Encoding) that makes data files completely unreadable to unauthorized users.
* **Permissions Management:** A dedicated **Permissions List** to display and control specific access levels (Admin/User) for every module.
* **Refresh Users Security:** A security tool that re-encrypts all user passwords in the database to maintain high-level protection against breaches.
* **Activity Log System (Audit Trail):** Every action (adding a client, viewing data, transactions) is automatically logged with a timestamp to monitor all system interactions.

---

## 🚀 Key Features

* **Client Management:** Comprehensive CRUD system (Add, Find, Update, Delete) with persistent data.
* **Transactions Module:** Secure Deposit, Withdraw, and Transfer operations with real-time balance validation.
* **Input Validation:** Robust sanitization to prevent invalid data entries and system crashes.
* **Data Persistence:** Robust **File Handling** to ensure all bank records, logs, and users are saved securely.

---

## 💻 Technical Implementation (Encryption Logic)

```cpp
// The core 5-layer encryption logic as implemented in the project:
string Encrypted = _EncryptText(_InvertTextCase(_AddRandomPadding(_EncryptText(Text, Key), Key)), Key);
return TextToHex(Encrypted);
