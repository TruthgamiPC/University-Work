<?php
session_start();
if (isset($_SESSION['userID']) === false) {
  $_SESSION['userID'] = 0;
}
if ($_SESSION['userID'] == 0) {
  header("Location: ../signin/signin.php");
}

// echo $_SESSION['checkoutSKU1'];
// echo "<br>";
// echo $_SESSION['checkoutSKU2'];
// echo "<br>";
// echo $_SESSION['checkoutSKU3'];

?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta name="description" content="">
  <meta name="author" content="Mark Otto, Jacob Thornton, and Bootstrap contributors">
  <meta name="generator" content="Hugo 0.79.0">
  <title>Checkout</title>

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

<body class="bg-light">

  <?php

      if(isset($_POST['clearBasket'])){
        $_SESSION['checkoutSKU1'] = 0;
        $_SESSION['checkoutSKU2'] = 0;
        $_SESSION['checkoutSKU3'] = 0;
        header("Location: checkout.php");
      }

      if(isset($_POST['continueShopping'])) {
        if (!$_SESSION['checkoutSKU1'] == 0 && !$_SESSION['checkoutSKU2'] == 0 && !$_SESSION['checkoutSKU3'] == 0) {
          echo '<script>alert("Your basket has its maximum 3 items, please either check out, or clear basket")</script>';
        } else {
          header("Location: ../landing/landing.php");
        }
      }

      include "../connection.php";
      $connection = openCon();

      $customerID = $_SESSION['userID'];

      $checkoutQ = "SELECT * FROM checkout WHERE IDcustomer = '$customerID'";
      $checkoutQResult = $connection->query($checkoutQ);

      if($checkoutQResult->num_rows > 0) {
        $checkoutResult = $checkoutQResult->fetch_array();
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

      $checkoutSKU1 = $_SESSION['checkoutSKU1'];
      $checkoutSKU2 = $_SESSION['checkoutSKU2'];
      $checkoutSKU3 = $_SESSION['checkoutSKU3'];

      if(!$checkoutSKU1 == 0) {
        $checkoutProductQ = "SELECT * FROM checkout_product WHERE SKU = '$checkoutSKU1'";
        $checkountProductQResult1 = $connection->query($checkoutProductQ);
        $checkoutProductResult1 = $checkountProductQResult1->fetch_array();
      }

      if(!$checkoutSKU2 == 0) {
        $checkoutProductQ = "SELECT * FROM checkout_product WHERE SKU = '$checkoutSKU2'";
        $checkountProductQResult2 = $connection->query($checkoutProductQ);
        $checkoutProductResult2 = $checkountProductQResult2->fetch_array();
      }

      if(!$checkoutSKU3 == 0) {
        $checkoutProductQ = "SELECT * FROM checkout_product WHERE SKU = '$checkoutSKU3'";
        $checkountProductQResult3 = $connection->query($checkoutProductQ);
        $checkoutProductResult3 = $checkountProductQResult3->fetch_array();
      }

      if(isset($_POST['placeOrder'])){
        $totalPrice = 0;
        if(!$checkoutSKU1 == 0) {
          $totalPrice = $totalPrice + $checkoutProductResult1['price'];
        }
        if(!$checkoutSKU2 == 0) {
          $totalPrice = $totalPrice + $checkoutProductResult2['price'];
        }
        if(!$checkoutSKU3 == 0) {
          $totalPrice = $totalPrice + $checkoutProductResult3['price'];
        }
        $date = date("Y-m-d");
        $branchID = "999";
        $status = "Processing";
        $orderType = "O";
        $employeeOnOrder = "1";
        $orderI = "INSERT INTO order_in (branchID, totalPrice, customerID, status, date, orderType, employeeOnOrder) VALUES ('$branchID', '$totalPrice', '$customerID', '$status', '$date', '$orderType', '$employeeOnOrder')";

        if($connection->query($orderI) === true) {
          $order_last_id = $connection->insert_id;

          if(!$checkoutSKU1 == 0) {
            $productOrderI1 = "INSERT INTO product_order_in (productSKU, orderID, quantity) VALUES ('$checkoutSKU1', '$order_last_id', '1')";
            $connection->query($productOrderI1);
          }
          if(!$checkoutSKU2 == 0) {
            $productOrderI2 = "INSERT INTO product_order_in (productSKU, orderID, quantity) VALUES ('$checkoutSKU2', '$order_last_id', '1')";
            $connection->query($productOrderI2);
          }
          if(!$checkoutSKU3 == 0) {
            $productOrderI3 = "INSERT INTO product_order_in (productSKU, orderID, quantity) VALUES ('$checkoutSKU3', '$order_last_id', '1')";
            $connection->query($productOrderI3);
          }
        }
        $_SESSION['checkoutSKU1'] = 0;
        $_SESSION['checkoutSKU2'] = 0;
        $_SESSION['checkoutSKU3'] = 0;
        header("Location: ../account/orders.php");
      }

      closeCon($connection);
  ?>




  <div class="container">
    <main>
      <div class="py-5 text-center">
        <img class="d-block mx-auto mb-4" src="../assets/brand/bootstrap-logo.svg" alt="" width="72" height="57">
        <h2>Checkout form</h2>
        <p class="lead">Below is an example form built entirely with Bootstrap’s form controls. Each required form group has a validation state that can be triggered by attempting to submit the form without completing it.</p>
      </div>

      <div class="row g-3">
        <div class="col-md-5 col-lg-4 order-md-last">
          <h4 class="d-flex justify-content-between align-items-center mb-3">
            <span class="text-muted">Your cart</span>
            <span class="badge bg-secondary rounded-pill">
              <?php
                $cartItems = 0;
                if(!$checkoutSKU1 == 0) {
                  $cartItems = $cartItems + 1;
                }
                if(!$checkoutSKU2 == 0) {
                  $cartItems = $cartItems + 1;
                }
                if(!$checkoutSKU3 == 0) {
                  $cartItems = $cartItems + 1;
                }
                echo $cartItems;
              ?>
            </span>
          </h4>
          <ul class="list-group mb-3">
            <li class="list-group-item d-flex justify-content-between lh-sm">
              <div>
                <h6 class="my-0">
                  <?php
                    if(!$_SESSION['checkoutSKU1'] == 0) {
                      echo $checkoutProductResult1['model'];
                    } else {
                      echo "Empty Basket Slot";
                    }
                  ?>
                </h6>
              </div>
              <span class="text-muted">
                <?php
                  if(!$_SESSION['checkoutSKU1'] == 0) {
                    echo $checkoutProductResult1['price'];
                  } else {
                    echo "£0";
                  }
                ?>
              </span>
            </li>
            <li class="list-group-item d-flex justify-content-between lh-sm">
              <div>
                <h6 class="my-0">
                  <?php
                    if(!$_SESSION['checkoutSKU2'] == 0) {
                      echo $checkoutProductResult2['model'];
                    } else {
                      echo "Empty Basket Slot";
                    }
                  ?>
                </h6>
              </div>
              <span class="text-muted">
                <?php
                  if(!$_SESSION['checkoutSKU2'] == 0) {
                    echo $checkoutProductResult2['price'];
                  } else {
                    echo "£0";
                  }
                ?>
              </span>
            </li>
            <li class="list-group-item d-flex justify-content-between lh-sm">
              <div>
                <h6 class="my-0">
                  <?php
                    if(!$_SESSION['checkoutSKU3'] == 0) {
                      echo $checkoutProductResult3['model'];
                    } else {
                      echo "Empty Basket Slot";
                    }
                  ?>
                </h6>
              </div>
              <span class="text-muted">
                <?php
                  if(!$_SESSION['checkoutSKU3'] == 0) {
                    echo $checkoutProductResult3['price'];
                  } else {
                    echo "£0";
                  }
                ?>
              </span>
            </li>
            <li class="list-group-item d-flex justify-content-between">
              <span>Total (GBP)</span>
              <strong>
                <?php
                  $totalPrice = 0;
                  if(!$checkoutSKU1 == 0) {
                    $totalPrice = $totalPrice + $checkoutProductResult1['price'];
                  }
                  if(!$checkoutSKU2 == 0) {
                    $totalPrice = $totalPrice + $checkoutProductResult2['price'];
                  }
                  if(!$checkoutSKU3 == 0) {
                    $totalPrice = $totalPrice + $checkoutProductResult3['price'];
                  }
                  echo "£" . $totalPrice;
                ?>
              </strong>
            </li>
          </ul>
          <form class="card p-2" method="post">
            <div class="input-group">
              <div class="input-group-append">
                <button type="submit" class="btn btn-secondary" name="clearBasket">Clear Basket</button>
                <button type="submit" class="btn btn-secondary" name="continueShopping">Continue Shopping</button>
              </div>
            </div>
          </form>
        </div>


        <div class="col-md-7 col-lg-8">
          <h4 class="mb-3">Billing address</h4>
          <form method="post" class="needs-validation" novalidate>
            <div class="row g-3">
              <div class="col-sm-6">
                <label for="firstName" class="form-label">First name</label>
                <input type="text" class="form-control" id="firstName" placeholder="" value="<?php echo $customerFirstName; ?>" required>
                <div class="invalid-feedback">
                  Valid first name is required.
                </div>
              </div>

              <div class="col-sm-6">
                <label for="lastName" class="form-label">Last name</label>
                <input type="text" class="form-control" id="lastName" placeholder="" value="<?php echo $customerLastName; ?>" required>
                <div class="invalid-feedback">
                  Valid last name is required.
                </div>
              </div>

              <div class="col-12">
                <label for="email" class="form-label">Email</label>
                <input type="email" class="form-control" id="email" placeholder="" value="<?php echo $customerEmail; ?>" required>
                <div class="invalid-feedback">
                  Please enter a valid email address for shipping updates.
                </div>
              </div>

              <div class="col-12">
                <label for="address" class="form-label">Address</label>
                <input type="text" class="form-control" id="address" placeholder="" value="<?php echo $customerAddress1; ?>" required>
                <div class="invalid-feedback">
                  Please enter your shipping address.
                </div>
              </div>

              <div class="col-12">
                <label for="address2" class="form-label">Address 2 <span class="text-muted">(Optional)</span></label>
                <input type="text" class="form-control" id="address2" placeholder="" value="<?php echo $customerAddress2; ?>">
              </div>

              <div class="col-md-5">
                <label for="country" class="form-label">Country</label>
                <select class="form-select" id="country" required>
                  <option value="">Choice</option>
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
                <input type="text" class="form-control" id="city" placeholder="" value="<?php echo $customerCity; ?>" required>
                <div class="invalid-feedback">
                  City Required
                </div>
              </div>

              <div class="col-md-3">
                <label for="zip" class="form-label">Post Code</label>
                <input type="text" class="form-control" id="postCode" placeholder="" value="<?php echo $customerPostCode; ?>" required>
                <div class="invalid-feedback">
                  Post Code Required.
                </div>
              </div>
            </div>

            <hr class="my-4">

            <h4 class="mb-3">Payment</h4>

            <div class="my-3">
              <div class="form-check">
                <input id="credit" name="paymentMethod" type="radio" class="form-check-input" checked required>
                <label class="form-check-label" for="credit">Credit card</label>
              </div>
              <div class="form-check">
                <input id="debit" name="paymentMethod" type="radio" class="form-check-input" required>
                <label class="form-check-label" for="debit">Debit card</label>
              </div>
            </div>

            <div class="row gy-3">
              <div class="col-md-6">
                <label for="cc-name" class="form-label">Name on card</label>
                <input type="text" class="form-control" id="cc-name" placeholder="" required>
                <small class="text-muted">Full name as displayed on card</small>
                <div class="invalid-feedback">
                  Name on card is required
                </div>
              </div>

              <div class="col-md-6">
                <label for="cc-number" class="form-label">Credit card number</label>
                <input type="text" class="form-control" id="cc-number" placeholder="" required>
                <div class="invalid-feedback">
                  Credit card number is required
                </div>
              </div>

              <div class="col-md-3">
                <label for="cc-expiration" class="form-label">Expiration</label>
                <input type="text" class="form-control" id="cc-expiration" placeholder="" required>
                <div class="invalid-feedback">
                  Expiration date required
                </div>
              </div>

              <div class="col-md-3">
                <label for="cc-cvv" class="form-label">CVV</label>
                <input type="text" class="form-control" id="cc-cvv" placeholder="" required>
                <div class="invalid-feedback">
                  Security code required
                </div>
              </div>
            </div>

            <hr class="my-4">

              <button type="submit" class="w-100 btn btn-primary btn-lg" name="placeOrder">Place Order</button>
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
