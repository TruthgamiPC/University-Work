<?php
  session_start();
  if (isset($_SESSION['userID']) === false) {
    $_SESSION['userID'] = 0;
  }
  $_SESSION['emailInUse'] = 0;

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

    $inputTitle = $_POST['title'];
    $inputFirstName = $_POST['firstName'];
    $inputLastName = $_POST['lastName'];
    $inputEmail = $_POST['email'];
    $inputPassword = $_POST['password'];
    $inputPhoneNo = $_POST['phoneNo'];
  }

  $emailQ = "SELECT * FROM customer_in WHERE email = '$inputEmail'";
  $emailQResult = $connection->query($emailQ);

  if ($emailQResult === false) {
    echo "We wrote a bad query";
  } else {
    if ($emailQResult->num_rows > 0) {
      $_SESSION['emailInUse'] = 1;
      closeCon($connection);
      header("Location: register.php");
    }
  }

  $addressI = "INSERT INTO address_in (postalCode, city, country, address1, address2) VALUES ('$inputPostalCode', '$inputCity', '$inputCountry', '$inputAddress1', '$inputAddress2')";
  if ($connection->query($addressI) === true) {
    $last_id = $connection->insert_id;
    //echo "New record created successfully. Last inserted ID is: " . $last_id;
  } else {
    echo "Error: " . $addressI . "<br>" . $connection->error;
  }

  $customerI = "INSERT INTO customer_in (title, firstName, lastName, email, addressID, phoneNumber, hashPassword) VALUES ('$inputTitle', '$inputFirstName', '$inputLastName', '$inputEmail', '$last_id', '$inputPhoneNo', '$inputPassword')";
  if ($connection->query($customerI) === true) {
    $customer_last_id = $connection->insert_id;
    $_SESSION['userID'] = $customer_last_id;
    header("Location: ../landing/landing.php");
  } else {
    echo "Error: " . $addressI . "<br>" . $connection->error;
  }


  closeCon($connection);

?>
