<?php

function openCon() {
  //Credentials
  $servername = "silva.computing.dundee.ac.uk:3306";
  $username = "20ac3u12";
  $password = "bac123";
  $database = "20ac3d12";
  //Create connection
  $conn = new mysqli($servername, $username, $password, $database);
  //Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }
  //Success Message for Testing
  //echo "Connected successfully";
  return $conn;
}

function closeCon($conn) {
  $conn -> close();
}
?>
