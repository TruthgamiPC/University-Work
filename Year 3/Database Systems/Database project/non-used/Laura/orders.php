

<head>
	<style type="text/css">

		#content {
			clear: both;
		}

		#solid {
			border-top: 3px solid #bbb;
		}

		#center {
			display: inline-block;
			float: left;
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

		.column {
			float: left;
  			width: 33.33%;
  			padding: 10px;
  			height: 150px;
		}

	</style>
</head>

<body>

<?php
include 'header.php';
?>

<div id="content">

<!-- NAVIGATION BAR -->
<!-- Reference: https://www.w3schools.com/w3css/tryit.asp?filename=tryw3css_navbar_border -->
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<div class="w3-bar w3-border w3-card-4 w3-light-grey" id="navBar">
  <a href="accountDetails.php" class="w3-bar-item w3-button"> Account Details </a>
  <a href="orders.php" class="w3-bar-item w3-button"> Orders </a>
  <a href="#" class="w3-bar-item w3-button">Link 2</a>
  <a href="#" class="w3-bar-item w3-button">Link 3</a>
</div>

<div id="center">
	<div id="pendingOrders">
		<h3> Pending Order </h3>
		<div class="order">
			<div class="column">
				<label> Order ID </label>
				<p> 15258934156 </p>

				<label> Tracking ID </label>
				<p> 15258934156 </p>
			</div>
			<div class="column">
				<label> Date: </label>
				<p> 15th March </p>
			</div>
			<div class="column">
				<label> Guide price: </label>
				<p> $59.99 </p>
				<label> Items: </label>
				<p> 55 </p>
			</div>
		</div>

	</div>

	<hr class="solid">

	<div id="pastOrders">
		<h3> Past Orders </h3>

			<div class="order">
				<div class="column">
					<label> Order ID </label>
					<p> 15258934156 </p>

					<label> Tracking ID </label>
					<p> 15258934156 </p>
				</div>
				<div class="column">
					<label> Date: </label>
					<p> 15th March </p>
				</div>
				<div class="column">
					<label> Guide price: </label>
					<p> $59.99 </p>
					<label> Items: </label>
					<p> 55 </p>
				</div>
			</div>

			<div class="order">

				<div class="column">
					<label> Order ID </label>
					<p> 15258934156 </p>

					<label> Tracking ID </label>
					<p> 15258934156 </p>
				</div>

				<div class="column">
					<label> Date: </label>
					<p> 15th March </p>
				</div>

				<div class="column">
					<label> Guide price: </label>
					<p> $59.99 </p>
					<label> Items: </label>
					<p> 55 </p>
				</div>

			</div>

			<div class="order">

				<div class="column">
					<label> Order ID </label>
					<p> 15258934156 </p>

					<label> Tracking ID </label>
					<p> 15258934156 </p>
				</div>

				<div class="column">
					<label> Date: </label>
					<p> 15th March </p>
				</div>

				<div class="column">
					<label> Guide price: </label>
					<p> $59.99 </p>
					<label> Items: </label>
					<p> 55 </p>
				</div>

			</div>

		</div>

	</div>

</div>

</div>




<?php
include 'footer.php';
?>


</body>
