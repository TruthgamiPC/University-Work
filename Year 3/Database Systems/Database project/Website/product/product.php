<?php
  session_start();
  if (isset($_SESSION['productID']) === false) {
    $_SESSION['productID'] = "0730143312042";
  }
  if (isset($_SESSION['userID']) === false) {
    $_SESSION['userID'] = 0;
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
  <title>Products</title>

  <link rel="canonical" href="https://getbootstrap.com/docs/5.0/examples/blog/">



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
  <link href="https://fonts.googleapis.com/css?family=Playfair&#43;Display:700,900&amp;display=swap" rel="stylesheet">
  <!-- Custom styles for this template -->
  <link href="blog.css" rel="stylesheet">
</head>

<body>

  <?php
    include "../connection.php";
    $connection = openCon();

    $currentSKU = $_SESSION['productID'];
    $productQ = "SELECT * FROM product_page WHERE SKU='$currentSKU'";

    $result = $connection->query($productQ);
    closeCon($connection);

    $resultProduct = $result->fetch_array();

    $resultSKU = $resultProduct['SKU'];
    $resultType = $resultProduct['type'];
    $resultBrand = $resultProduct['brand'];
    $resultModel = $resultProduct['model'];
    $resultPrice = $resultProduct['price'];
    $resultDesc = $resultProduct['productDescription'];
    $resultImage = $resultProduct['meta_data'];

    $resultStock = 0;

    if ($result->num_rows > 0) {
      $resultStock = $resultStock + $resultProduct['quantity'];
      while ($resultProduct = $result->fetch_array()) {
        $resultStock = $resultStock + $resultProduct['quantity'];
      }
      $result->free();
    }

  ?>

  <?php
      if(isset($_POST['AccountOrRegister'])) {
        if (!$_SESSION['userID'] == 0) {
          header("Location: ../account/account.php");
        } else {
          header("Location: ../signin/register.php");
        }
      }

      if(isset($_POST['addToCart'])) {
        if ($_SESSION['userID'] == 0) {
          header("Location: ../signin/signin.php");
        }
        if($_SESSION['checkoutSKU1'] == 0) {
          $_SESSION['checkoutSKU1'] = $resultSKU;
          header("Location: ../checkout/checkout.php");
        } else {
          if($_SESSION['checkoutSKU2'] == 0) {
            $_SESSION['checkoutSKU2'] = $resultSKU;
            header("Location: ../checkout/checkout.php");
          } else {
            if ($_SESSION['checkoutSKU3'] == 0) {
              $_SESSION['checkoutSKU3'] = $resultSKU;
              header("Location: ../checkout/checkout.php");
            } else {
              header("Location: ../checkout/checkout.php");
            }
          }
        }
      }
  ?>


  <div class="container">
    <header class="blog-header py-3">
      <div class="row flex-nowrap justify-content-between align-items-center">
        <div class="col-4 pt-1">
          <a class="link-secondary" href="../landing/landing.php">Home</a>
        </div>
        <div class="col-4 text-center">
          <a class="blog-header-logo text-dark" href="#">MASTER RACE PARTS</a>
        </div>
        <div class="col-4 d-flex justify-content-end align-items-center">
          <a class="link-secondary" href="#" aria-label="Search">
            <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" class="mx-3" role="img" viewBox="0 0 24 24">
              <title>Search</title>
              <circle cx="10.5" cy="10.5" r="7.5" />
              <path d="M21 21l-5.2-5.2" />
            </svg>
          </a>
          <form method="post">
            <button type="submit" class="btn btn-sm btn-outline-secondary" name="AccountOrRegister">
              <?php
                if (!$_SESSION['userID'] == 0) {
                 echo "Account";
                } else {
                  echo "Register";
                $_SESSION['userID'] = 0;
                }
              ?>
            </button>
          </form>
          <a class="btn btn-sm btn-outline-secondary" href="../signin/signin.php">
            <?php
              if (!$_SESSION['userID'] == 0) {
                echo "Sign Out";
              } else {
                echo "Sign In";
               $_SESSION['userID'] = 0;
              }
            ?>
          </a>
        </div>
      </div>
    </header>









    <main class="container">

      <div class="row mb-2">
        <div class="col-md-6">
          <div class="row g-0 border rounded overflow-hidden flex-md-row mb-4 shadow-sm h-md-250 position-relative">
            <img src="<?php echo $resultImage ?>" alt="Product Image" height="225">
          </div>
        </div>
        <div class="col-md-6">
          <div class="row g-0 border rounded overflow-hidden flex-md-row mb-4 shadow-sm h-md-250 position-relative">
            <h4>
              <?php
                echo $resultBrand;
              ?>
            </h4>
            <p>
              <?php
                echo $resultModel;
              ?>
            </p>
            <p>
              <?php
                echo "Type of Part " . $resultType . " From Our Partners at " . $resultBrand;
              ?>
            </p>
            <p>
              <?php
                echo $resultDesc;
              ?>
            </p>
            <p>
              <?php
                echo "Currently in stock: " . $resultStock;
              ?>
            </p>
          </div>
        </div>
      </div>

      <div class="row">
        <div class="col-md-8">
          <nav class="blog-pagination" aria-label="Pagination">
            <a class="btn btn-outline-primary disabled" href="#">£<?php echo $resultPrice ?></a>
            <form method="post">
              <button type="submit" class="btn btn-outline-secondary" name="addToCart" tabindex="-1" aria-disabled="true">Add To Basket</button>
            </form>
          </nav>

        </div>

      </div><!-- /.row -->

    </main><!-- /.container -->

    <footer class="blog-footer">
      <p>Master Race Parts (2017-20)</p>
      <p>
        <a href="#">Back to top</a>
      </p>
    </footer>



</body>

</html>
