<h1>Attendance Tracker</h1>

<h2>Description</h2>

<p>This project is a comprehensive system designed to streamline the management and monitoring of student attendance. It allows administrators to efficiently register students, track their attendance, and manage their data. With features like student login, attendance marking, and data management, it ensures accurate and up-to-date records, making it an essential tool for educational institutions aiming to maintain organized and reliable attendance information.</p>

<h2>Features</h2>
<ul>
	<li><strong>Admin Login:</strong> Secure access for administrators to manage student data.</li>
  	<li><strong>Register Student:</strong> Register new students with necessary details.</li>
  	<li><strong>Check List of All Students Registered:</strong> View the list of all registered students.</li>
  	<li><strong>Get List of Students Registered by Username:</strong> Retrieve student details by username.</li>
  	<li><strong>Delete Student Data:</strong> Delete data of a specific student.</li>
  	<li><strong>Delete All Registered Students:</strong> Remove all student records.</li><br>
  	<li><strong>Student Login:</strong> Allows students to log in and mark their attendance.</li>
 	<li><strong>Mark Attendance:</strong> Students can mark their attendance for the day.</li>
  	<li><strong>Count Attendance:</strong> Students can view their total attendance count.</li>
</ul>

<h2>Admin Login</h2>
<p>
	<strong>Username</strong>: <code>admin</code><br>
	<strong>Password</strong>: <code>spark</code><br>
</p>

<h2>System Requirements</h2>
<ul>
	<li>C++ <strong>20</strong></li>
  	<li>Terminal or Command Prompt</li>
</ul>

<h2>Step for Execution</h2>
<ol>
	<li>
		<h4>Open the Terminal and Clone the Repository</h4>
	   	<code>git clone https://github.com/Melvin-Shalom/Attendance-Tracker.git</code><br>
	</li>
	<li>
		<h4>Navigate to the project directory</h4>
	    	<code>cd Attendance_Tracker/</code>
	</li>
	<li>
    		<h4>Compile the program:</h4>
    		<code>g++ attM.cpp -o attendance</code>
	</li>
  	<li>
	    	<h4>Run the program:</h4>
    		<code>./attendance</code>
  	</li>
</ol>

## Usage

Once compiled and executed, users interact with the system via a command-line interface.

- **Admins** can:
  - Log in using the default credentials
  - Register or remove students
  - Check list of Students registered and view Currently Registered Student's Roll Numbers
  - View student lists and attendance data

- **Students** can:
  - Log in with their username
  - Mark daily attendance
  - Check their attendance history

## Future Scope

- Implement password encryption for better security
- Add GUI support using a cross-platform framework (e.g., Qt)
- Enable CSV export/import for easier data handling
- Add attendance analytics and visualization features
- Role-based access (e.g., teachers, admins, students)

## Author

Developed with 💻 and ☕ by [Melvin Shalom](https://github.com/Melvin-Shalom)

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
