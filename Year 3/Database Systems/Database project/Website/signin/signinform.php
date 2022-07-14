<?php
  session_start();

  include "../connection.php";
  $connection = openCon();

  // Check if the form is submitted
  if ( isset( $_POST['submit'] ) ) {
    // retrieve the form data by using the element's name attributes value as key
    $email = $_POST['emailInput'];
    $password = $_POST['passwordInput'];
    // display the results
    //echo '<h3>Form POST Method</h3>'; echo 'Your email is ' . $email . ' and your password is ' . $password;
  }

  $emailQ = "SELECT * FROM user_signin WHERE email = '$email'";
  $result = $connection->query($emailQ);
  closeCon($connection);

  if ($result->num_rows == 0) {
    $_SESSION['failedLogin'] = 1;
    header("Location: signin.php");
  } else {
    $resultRow = $result->fetch_array();
    if ($resultRow['hashPassword'] == $password) {
      $_SESSION['failedLogin'] = 0;
      $_SESSION['userID'] = $resultRow['IDcustomer'];
      $_SESSION['checkoutSKU1'] = 0;
      $_SESSION['checkoutSKU2'] = 0;
      $_SESSION['checkoutSKU3'] = 0;
      header("Location: ../landing/landing.php");
    } else {
      $_SESSION['failedLogin'] = 1;
      header("Location: signin.php");
    }
  }

?>
