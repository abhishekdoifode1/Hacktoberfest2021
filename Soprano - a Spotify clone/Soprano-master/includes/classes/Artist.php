<?php
	class Artist {

		private $con;
		private $id;
		private $count;
		private $name;

		public function __construct($con, $id) {
			$this->con = $con;
			$this->id = $id;

			$query = mysqli_query($this->con, "SELECT * FROM artists WHERE id='$this->id'");
			$this->mysqliData = mysqli_fetch_array($query);
			$this->count = $this->mysqliData['count'];
			$this->name = $this->mysqliData['name'];
		}

		public function getId() {
			return $this->id;
		}

		public function getName() {
			return $this->name;
		}

		public function getCount() {
			return $this->count;
		}
		
		public function getSongIds() {

			$query = mysqli_query($this->con, "SELECT id FROM songs WHERE artist='$this->id' ORDER BY plays ASC");

			$array = array();

			while($row = mysqli_fetch_array($query)) {
				array_push($array, $row['id']);
			}

			return $array;

		}
	}
?>