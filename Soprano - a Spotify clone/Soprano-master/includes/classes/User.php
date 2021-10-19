<?php
	class User {

		private $con;
		private $email;

		public function __construct($con, $email) {
			$this->con = $con;
			$this->email = $email;
		}

		public function getEmail() {
			return $this->email;
		}

		public function getFirstAndLastName() {
			$query = mysqli_query($this->con, "SELECT concat(firstName, ' ', lastName) as 'name'  FROM users WHERE email='$this->email'");
			$row = mysqli_fetch_array($query);
			return $row['name'];
		}

	}
?>