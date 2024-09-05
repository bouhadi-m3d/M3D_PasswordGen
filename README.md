# M3D-BOUHADI Password Generator

## Introduction
The M3D-BOUHADI Password Generator is a simple yet effective C++ tool designed to generate strong, random passwords. It allows users to create secure passwords based on customizable criteria, making it easier to manage credentials across various platforms.

## Key Features
- **Customizable Password Length:** Create passwords with lengths ranging from 8 to 16 characters.
- **Flexible Character Set:** Include lowercase letters, uppercase letters, digits, and special characters.
- **Password Management:** Save generated passwords along with associated platform names and usernames.
- **Organized Viewing:** View saved passwords in a neatly formatted table.

## Installation Instructions
1. Clone the repository using the following command:
   `git clone https://github.com/bouhadi-m3d/M3D_PasswordGen.git`
2. Navigate to the `src` directory:
   `cd M3D_PasswordGen/src`
3. Compile the source code with:
   `g++ -o M3D_PasswordGen main.cpp`
   Ensure you have a C++ compiler installed. If additional dependencies are required, they will be specified in the project documentation.

## Usage
1. Run the executable:
   `./M3D_PasswordGen`
2. Follow the on-screen instructions to:
   - Generate a new password
   - View previously saved passwords
   - Exit the program

## Project Structure
- `src/`: Contains source code files and the compiled executable
- `main.cpp`: The main source code file
- `M3D_PasswordGen.exe`: Compiled executable for Windows (if applicable)
- `passwords.csv`: CSV file where saved passwords are stored (created after the first password is saved)

## Security Advisory
Passwords are stored in plaintext within the `passwords.csv` file. For enhanced security, consider implementing encryption for stored passwords in future updates. Plaintext storage can expose sensitive information if the file is accessed by unauthorized individuals.

## Contributions
We welcome contributions, bug reports, and feature requests. Please visit the [issues page](https://github.com/bouhadi-m3d/M3D_PasswordGen/issues) to report issues or suggest improvements.

## Author
- GitHub: [@bouhadi-m3d](https://github.com/bouhadi-m3d)
- X: [@ChrolloM3d](https://x.com/ChrolloM3d)
