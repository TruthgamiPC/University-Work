<?php
session_start();
if (isset($_SESSION['userID']) === false) {
  $_SESSION['userID'] = 0;
}
if ($_SESSION['userID'] == 0) {
  header("Location: ../signin/signin.php");
}
?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta name="description" content="">
  <meta name="author" content="Mark Otto, Jacob Thornton, and Bootstrap contributors">
  <meta name="generator" content="Hugo 0.79.0">
  <title>Account-customer</title>

  <link rel="canonical" href="https://getbootstrap.com/docs/5.0/examples/checkout/">



  <!-- Bootstrap core CSS -->
  <link href="../assets/dist/css/bootstrap.min.css" rel="stylesheet">

  <style>
    .bd-placeholder-img {
      font-size: 1.125rem;
      text-anchor: middle;
      -webkit-user-select: none;
      -moz-user-select: none;
      user-select: none;
    }

    @media (min-width: 768px) {
      .bd-placeholder-img-lg {
        font-size: 3.5rem;
      }
    }
  </style>


  <!-- Custom styles for this template -->
  <link href="form-validation.css" rel="stylesheet">
</head>

  <?php
    include "../connection.php";
    $connection = openCon();

    $customerID = $_SESSION['userID'];

    $checkoutQ = "SELECT * FROM account WHERE IDcustomer = '$customerID'";
    $checkoutQResult = $connection->query($checkoutQ);

    if($checkoutQResult->num_rows > 0) {

      $checkoutResult = $checkoutQResult->fetch_array();

      $customerPhoneNo = $checkoutResult['phoneNumber'];
      $customerTitle = $checkoutResult['title'];
      $customerFirstName = $checkoutResult['firstName'];
      $customerLastName = $checkoutResult['lastName'];
      $customerEmail = $checkoutResult['email'];
      $customerAddressID = $checkoutResult['addressID'];
      $customerAddress1 = $checkoutResult['address1'];
      $customerAddress2 = $checkoutResult['address2'];
      $customerPostCode = $checkoutResult['postalCode'];
      $customerCity = $checkoutResult['city'];
      $customerCountry = $checkoutResult['country'];
    }

  ?>


<body class="bg-light">
  <div class="container">
    <main>
      <div class="py-5 text-center">
        <img class="d-block mx-auto mb-4" src="../assets/brand/bootstrap-logo.svg" alt="" width="72" height="57">
        <h2>Update Your Information</h2>
        <p class="lead">Your Current Information Is Displayed</p>
      </div>

      <div class="row g-3">
        <div>
          <form class="needs-validation" novalidate action="accountform.php" method="post">
            <div class="row g-3">

              <div class="col-12">
                <label for="email" class="form-label">Email</label>
                <input type="email" class="form-control" id="email" placeholder="" value="<?php echo $customerEmail; ?>" readonly>
                <div class="invalid-feedback">
                  Please enter a valid email address.
                  <?php
                    if($_SESSION['emailInUse'] == 1) {
                      echo " THE EMAIL YOU TRIED IS ALREADY BEING USED. TRY ANOTHER.";
                    }
                      $_SESSION['emailInUse'] = 0;
                    ?>
                </div>
              </div>

              <div class="col-sm-6">
                <label for="password" class="form-label">Password</label>
                <input type="password" class="form-control" id="password" name="password" placeholder="" value="" required>
                <div class="invalid-feedback">
                  Please enter a password
                </div>
              </div>

              <div class="col-sm-6">
                <label for="country" class="form-label">Title</label>
                <input type="text" class="form-control" id="Title" placeholder="" value="<?php echo $customerTitle; ?>" readonly>
                <div class="invalid-feedback">
                  Valid first Title is required.
                </div>
              </div>

              <div class="col-sm-6">
                <label for="firstName" class="form-label">First name</label>
                <input type="text" class="form-control" id="firstName" placeholder="" value="<?php echo $customerFirstName; ?>" readonly>
                <div class="invalid-feedback">
                  Valid first name is required.
                </div>
              </div>

              <div class="col-sm-6">
                <label for="lastName" class="form-label">Last name</label>
                <input type="text" class="form-control" id="lastName" placeholder="" value="<?php echo $customerLastName; ?>" readonly>
                <div class="invalid-feedback">
                  Valid last name is required.
                </div>
              </div>

              <div class="col-12">
                <label for="address" class="form-label">Address</label>
                <input type="text" class="form-control" id="address1" name="address1" placeholder="" value="<?php echo $customerAddress1; ?>" required>
                <div class="invalid-feedback">
                  Please enter your shipping address.
                </div>
              </div>

              <div class="col-sm-6">
                <label for="address2" class="form-label">Address 2 <span class="text-muted">(Optional)</span></label>
                <input type="text" class="form-control" id="address2" name="address2" placeholder="" value="<?php echo $customerAddress2; ?>">
              </div>

              <div class="col-sm-6">
                <label for="address2" class="form-label">Phone Number</label>
                <input type="text" class="form-control" id="phoneNo" name="phoneNo" placeholder="" value="<?php echo $customerPhoneNo; ?>">
              </div>

              <div class="col-md-5">
                <label for="country" class="form-label">Country</label>
                <select class="form-select" id="country" name="country" required>
                  <option value="">Choose...</option>
                  <option>England</option>
                  <option>Scotland</option>
                  <option>Northen Ireland</option>
                  <option>Wales</option>
                </select>
                <div class="invalid-feedback">
                  Please select a valid country.
                </div>
              </div>

              <div class="col-md-4">
                <label for="zip" class="form-label">City</label>
                <input type="text" class="form-control" id="city" name="city" placeholder="" value="<?php echo $customerCity; ?>" required>
                <div class="invalid-feedback">
                  City Required
                </div>
              </div>

              <div class="col-md-3">
                <label for="zip" class="form-label">Post Code</label>
                <input type="text" class="form-control" id="postCode" name="postalCode" placeholder="" value="<?php echo $customerPostCode; ?>" required>
                <div class="invalid-feedback">
                  Post Code Required.
                </div>
              </div>
            </div>
            <hr class="my-4">
            <button class="w-100 btn btn-primary btn-lg" type="submit" name="submit">Update</button>
            <hr class="my-4">
            <button class="w-100 btn btn-primary btn-lg" type="button" onclick="document.location='../landing/landing.php'">Cancel</button>
            <hr class="my-4">
            <button class="w-100 btn btn-primary btn-lg" type="button" onclick="document.location='orders.php'">View My Orders</button>
          </form>
        </div>
      </div>
    </main>

    <footer class="my-5 pt-5 text-muted text-center text-small">
      <p class="mb-1">&copy; 2017–2020 Company Name</p>
      <ul class="list-inline">
        <li class="list-inline-item"><a href="#">Privacy</a></li>
        <li class="list-inline-item"><a href="#">Terms</a></li>
        <li class="list-inline-item"><a href="#">Support</a></li>
      </ul>
    </footer>
  </div>


  <script src="../assets/dist/js/bootstrap.bundle.min.js"></script>

  <script src="form-validation.js"></script>
</body>
</html>