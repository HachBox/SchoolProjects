<html>
	<head><title>0411 466 class example</title></head>
	<body>

		<form method="POST" action="">
			<input type="text" name="blah"/>
			<input type="submit"/>
		</form>

		<?php
	  $_GET[""];
	  $input =  $_POST["blah"];
	  echo $input;
	  include 'passwords.php';

	  try { //if something goes wrong, an exception is thrown
	  $dsn = "mysql:host=courses;dbname=z123456";
	  $pdo = new PDO($dsn, $username, $password);

	  $sql = "SELECT * FROM Customers WHERE customerNumber = ?";

	  echo $sql . "<br />";	//prints out SQL statement

	  $result = $pdo ->prepare($sql);

	  $result->execute(array($input));

	  $rows = $results->fetchAll();	  //assumingit works

	  echo "<pre>";
		print_r($rows);
		echo "</pre>";
	  }
	  catch(PDOexception $e) { //handle that exception
	  echo "Connection to database failed: " . $e->getMessage();
	  }

	  ?>

	</body>
</html>
