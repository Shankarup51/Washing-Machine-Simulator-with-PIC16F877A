🧺 Washing Machine Simulator with PIC16F877A
This project simulates the core operations of a washing machine using the PIC16F877A microcontroller. The embedded C code is developed with MPLAB X IDE and compiled using the XC8 compiler. The entire logic is thoroughly tested and simulated using PICSimLab on the PICGenios board, providing a visual representation of the washing machine's stages.

🧾 Setup Guide
To get started with this project, ensure you have the necessary tools installed. Refer to the Installation Guide (if you have one, otherwise this can be a placeholder for future detailed steps) for comprehensive instructions on setting up MPLAB X IDE, the XC8 Compiler, and PICSimLab.

🛠️ Tool Installation Overview
MPLAB X IDE: Download and install the latest version.

XC8 Compiler: Install this compiler, typically integrated with MPLAB X IDE.

PICSimLab: Download and install the simulator.

💻 Tools & Technologies Used
Microcontroller: PIC16F877A

Development Board: PICGenios

Integrated Development Environment (IDE): MPLAB X IDE

Compiler: MPLAB XC8 Compiler

Simulator: PICSimLab

📂 Folder Structure
washing-machine-simulator/
├── source_files/    # All .c source code files
├── header_files/    # All .h header files
├── README.md        # Project overview and instructions
└── <MPLAB_Project_Directory>/  # MPLAB X IDE project files (e.g., dist/, build/, etc.)
⚙️ How to Run the Project
Follow these steps to build and simulate the washing machine project:

🧱 Step 1: Open and Build in MPLAB X IDE
Open Project: Launch MPLAB X IDE. You can either create a new project and import the source_files and header_files, or open an existing project if you have one.

Compiler Selection: Ensure that the XC8 compiler is correctly installed and selected for your project.

Clean and Build: Use the Clean and Build Project option (the hammer icon in the toolbar) to compile your code. This process will automatically generate the necessary .hex file, which is required for simulation. You'll typically find this .hex file in the dist/default/production/ subdirectory of your MPLAB project.

🧪 Step 2: Simulate in PICSimLab
Launch PICSimLab: Start the PICSimLab application.

Select Board: Choose the PICGenios board from the available options.

Select Microcontroller: Select the PIC16F877A microcontroller.

Load Hex File: Load the .hex file generated in Step 1 (e.g., washing-machine-simulator.X.production.hex from your MPLAB project's dist directory).

Start Simulation: Begin the simulation and observe the washing machine's behavior through the simulated LEDs or other components on the PICGenios board.

🎯 Features
This simulation demonstrates fundamental embedded systems concepts through:

Stage Simulation: Accurately simulates the core washing machine stages: Washing, Rinsing, and Spinning.

Time-Based Transitions: Implements realistic time-based transitions between stages using delay logic.

Visual Feedback: Provides clear visual feedback on the current stage through simulated LEDs.

Educational Value: Serves as an excellent example for learning embedded systems design and microcontroller programming with the PIC16F877A.

📸 Demo
Check out this Demonstration Video (Link to video here) to see the Washing Machine Simulator in action, showcasing its real-time working.

📑 License
This project is open-source and released under the MIT License. You are free to use, modify, and distribute it for educational or non-commercial purposes.

🙋‍♂️ Author
Umashankar
Final Year B.Tech Student, Computer Science and Technology
