<?php
include 'header.php';

$idnumber = "00000";
$name = "HOLDER";
$email = "blank@blank.com";
$phone = "000000000";
$address = "22 Shepherd's Loan Dundee DD2 1AX";
$branch = "nonexistent";
$manager = "Charles Lindburgh III";

include 'employeeNavbar.php';

?>
  <style type="text/css">

		#content {
			clear: both;
		}

		#solid {
			border-top: 3px solid #bbb;
		}

		#center {
			display: inline-block;
			background-color:rgba(121, 189, 143, 0.3);
			width: 90%;
			padding: 20px;
			margin: 50px 5%;
		}

		.order {
			display: inline-block;
			text-align: center;
			width: 80%;
			margin: 10px 10%;
			padding: 10px;
			background-color: rgba(44, 67, 80, 0.5);
		}

	</style>

<div id="center">
  <div class="staffInfo">
    <div id="employeeInfo">
      <h3> <?php echo $name ?> </h3>
      <div class="info">
        <div class="row">
          <div class="col">
            <div class="column">
              <label><b>Employee ID</b></label>
              <p><?php echo $idnumber ?></p>

              <label><b>E-mail</b></label>
              <p><?php echo $email ?></p>
            </div>
          </div>

          <div class="col">
            <div class="column">
              <label><b>Phone Number</b></label>
              <p><?php echo $phone ?></p>
              <label><b>Manager</b></label>
              <p> <?php echo $manager ?> </p>
            </div>
          </div>
          <div class="col">
            <div class="column">
              <label><b>Branch</b></label>
              <p> <?php echo $branch ?> </p>
            </div>
          </div>
        </div>
        <div class = "row">
          <div class = "col">
            <label><b>Address</b></label>
            <p> <?php echo $address ?> </p>
          </div>
        </div>
      </div>

    </div>
  </div>
</div>

<!-- possible info populating ???? -->
<!--< ?php
$stmt = $dbh->prepare("INSERT INTO REGISTRY (name, value) VALUES (:name, :value)");
$stmt->bindParam(':name', $name);
$stmt->bindParam(':value', $value);

// insert one row
$name = 'one';
$value = 1;
$stmt->execute();

// insert another row with different values
$name = 'two';
$value = 2;
$stmt->execute();
?>
 -->

<?php
include 'footer.php';
?>
