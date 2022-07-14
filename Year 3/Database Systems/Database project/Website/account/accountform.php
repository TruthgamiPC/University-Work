<?php
  session_start();
  if (isset($_SESSION['userID']) === false) {
    $_SESSION['userID'] = 0;
    header("Location: ../signin/signin.php");
  }

  include "../connection.php";
  $connection = openCon();

  // Check if the form is submitted
  if ( isset( $_POST['submit'] ) ) {
    // retrieve the form data by using the element's name attributes value as key
    $inputPostalCode = $_POST['postalCode'];
    $inputCity = $_POST['city'];
    $inputCountry = $_POST['country'];
    $inputAddress1 = $_POST['address1'];
    $inputAddress2 = $_POST['address2'];

    $inputPassword = $_POST['password'];
    $inputPhoneNo = $_POST['phoneNo'];

    $userID = $_SESSION['userID'];
  }

  $addressLookup = "SELECT addressID FROM checkout WHERE IDcustomer = '$userID'";
  $resultQ = $connection->query($addressLookup);
  $resultQArray = $resultQ->fetch_array();
  if ($resultQ->num_rows > 0) {
    $addressLookupResult = $resultQArray['addressID'];
    $addressUpdate = "UPDATE address_in SET postalCode='$inputPostalCode', city='$inputCity', country='$inputCountry', address1='$inputAddress1', address2='$inputAddress2' WHERE addressID='$addressLookupResult'";
    $connection->query($addressUpdate);
  } else {
    echo "Error: " . $addressUpdate . "<br>" . $connection->error;
  }

  $accountUpdate = "UPDATE account_update SET hashPassword='$inputPassword', phoneNumber='$inputPhoneNo' WHERE IDcustomer = '$userID'";
  $connection->query($accountUpdate);


  closeCon($connection);

  header("Location: account.php");

?>
