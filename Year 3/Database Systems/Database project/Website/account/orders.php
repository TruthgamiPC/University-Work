<?php
session_start();
if (isset($_SESSION['userID']) === false) {
  $_SESSION['userID'] = 0;
  header("Location: ../signin/signin.php");
}

$userID = $_SESSION['userID'];

?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta name="description" content="">
  <meta name="author" content="Mark Otto, Jacob Thornton, and Bootstrap contributors">
  <meta name="generator" content="Hugo 0.79.0">
  <title>Orders - Customer</title>

  <link rel="canonical" href="https://getbootstrap.com/docs/5.0/examples/album/">



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

</head>



<body>
  <header>
    <div class="collapse bg-dark" id="navbarHeader">
      <div class="container">
        <div class="row">
          <div class="col-sm-8 col-md-7 py-4">
            <h4 class="text-white">Orders</h4>
          </div>
          <div class="col-sm-4 offset-md-1 py-4">
            <h4 class="text-white"></h4>
            <ul class="list-unstyled">
              <li><a href="../signin/signin.php" class="text-white">
                  <?php
                  if (!$_SESSION['userID'] == 0) {
                    echo "Sign Out";
                  } else {
                    echo "Sign In";
                    $_SESSION['userID'] = 0;
                  }
                ?>
                </a></li>
                <li><a href="../landing/landing.php" class="text-white">Home</a></li>
              <!-- <li><a href="#" class="text-white"></a></li>
              <li><a href="#" class="text-white"></a></li> -->
            </ul>
          </div>
        </div>
      </div>
    </div>
    <div class="navbar navbar-dark bg-dark shadow-sm">
      <div class="container">
        <a href="#" class="navbar-brand d-flex align-items-center">
          <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" fill="currentColor" class="bi bi-tools" viewBox="0 0 16 16">
            <path fill-rule="evenodd"
              d="M0 1l1-1 3.081 2.2a1 1 0 0 1 .419.815v.07a1 1 0 0 0 .293.708L10.5 9.5l.914-.305a1 1 0 0 1 1.023.242l3.356 3.356a1 1 0 0 1 0 1.414l-1.586 1.586a1 1 0 0 1-1.414 0l-3.356-3.356a1 1 0 0 1-.242-1.023L9.5 10.5 3.793 4.793a1 1 0 0 0-.707-.293h-.071a1 1 0 0 1-.814-.419L0 1zm11.354 9.646a.5.5 0 0 0-.708.708l3 3a.5.5 0 0 0 .708-.708l-3-3z" />
            <path fill-rule="evenodd"
              d="M15.898 2.223a3.003 3.003 0 0 1-3.679 3.674L5.878 12.15a3 3 0 1 1-2.027-2.027l6.252-6.341A3 3 0 0 1 13.778.1l-2.142 2.142L12 4l1.757.364 2.141-2.141zm-13.37 9.019L3.001 11l.471.242.529.026.287.445.445.287.026.529L5 13l-.242.471-.026.529-.445.287-.287.445-.529.026L3 15l-.471-.242L2 14.732l-.287-.445L1.268 14l-.026-.529L1 13l.242-.471.026-.529.445-.287.287-.445.529-.026z" />
          </svg>
          <strong>MASTER RACE PARTS</strong>
        </a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarHeader" aria-controls="navbarHeader" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
      </div>
    </div>
  </header>

  <main>
    <?php
      include "../connection.php";
      $connection = openCon();

      $last3orders = "SELECT * FROM order_display WHERE customerID = '$userID' ORDER BY date DESC LIMIT 3";
      $result = $connection->query($last3orders);

      $resultArray = $result->fetch_array();

      closeCon($connection);

      // if ($result === false) {
      //   echo "We wrote a bad query";
      // } else {
      //   echo "We DIDN'T write a bad query";
      // }

    ?>


    <section class="py-5 text-center container">
      <div class="row py-lg-5">
        <div class="col-lg-6 col-md-8 mx-auto">
          <h1 class="fw-light">Your Last 3 Orders</h1>
        </div>
      </div>
    </section>

    <form method="post">
      <div class="album py-5 bg-light">
        <div class="container">
          <div class="row row-cols-1 row-cols-sm-2 row-cols-md-3 g-3">
            <div class="col">
              <div class="card shadow-sm">
                <div class="card-body">
                  <p>Order Reference Number: <?php echo $resultArray['IDorder'] ?></p>
                  <p>Order Total Price: <?php echo $resultArray['totalPrice'] ?></p>
                  <p>Order Status: <?php echo $resultArray['status'] ?></p>
                  <p>Order Date: <?php echo $resultArray['date'] ?></p>
                </div>
              </div>
            </div>

            <?php
              $resultArray = $result->fetch_array();
            ?>

            <div class="col">
              <div class="card shadow-sm">
                <div class="card-body">
                  <p>Order Reference Number: <?php echo $resultArray['IDorder'] ?></p>
                  <p>Order Total Price: <?php echo $resultArray['totalPrice'] ?></p>
                  <p>Order Status: <?php echo $resultArray['status'] ?></p>
                  <p>Order Date: <?php echo $resultArray['date'] ?></p>
                </div>
              </div>
            </div>

            <?php
              $resultArray = $result->fetch_array();
            ?>

            <div class="col">
              <div class="card shadow-sm">
                <div class="card-body">
                  <p>Order Reference Number: <?php echo $resultArray['IDorder'] ?></p>
                  <p>Order Total Price: <?php echo $resultArray['totalPrice'] ?></p>
                  <p>Order Status: <?php echo $resultArray['status'] ?></p>
                  <p>Order Date: <?php echo $resultArray['date'] ?></p>
                </div>
              </div>
            </div>
          </div>

        </div>
      </div>
      </div>
    </form>
  </main>

  <footer class="text-muted py-5">
    <div class="container">
      <p class="float-end mb-1">
        <a href="#">Employee Login</a>
      </p>
    </div>
  </footer>


  <script src="../assets/dist/js/bootstrap.bundle.min.js"></script>


</body>

</html>
