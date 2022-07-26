<head>

	<style>

		#centerBlock {
			display: inline-block;
			float: left;
			background-color:rgba(121, 189, 143, 0.3); 
			width: 90%;
			padding: 20px;
			margin: 50px 5%;
		}

		.item {
			clear: both;
			display: inline-block;
			width: 90%;	
			
		}

		.image {
			display: inline-block;
			width: 30%;
		}

		.information {
			float: right;
			width: 60%;
		}


		hr.solid {
		  border-top: 3px solid #bbb;
		}



	</style>

</head>

<?php
include 'header.php';
?> 

<!-- NAVIGATION BAR -->
<!-- Reference: https://www.w3schools.com/w3css/tryit.asp?filename=tryw3css_navbar_border -->
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<div class="w3-bar w3-border w3-card-4 w3-light-grey" id="navBar">
  <a href="accountDetails.php" class="w3-bar-item w3-button"> Account Details </a>
  <a href="orders.php" class="w3-bar-item w3-button"> Orders </a>
  <a href="#" class="w3-bar-item w3-button">Link 2</a>
  <a href="#" class="w3-bar-item w3-button">Link 3</a>
</div>

<div id="centerBlock">
	<div class="item">
		<div class="image">
			<img src="">
		</div>
		<div class="information">
			<p> Name: </p> <p> </p>
			<p> Model: </p> <p> </p>
			<p> Price: </p> <p> </p>
			<p> I think there should be a picture on the left side but we store none in the database so  ¯\_(ツ)_/¯ </p>
		</div>
	</div>

	<hr class="solid">

	<div class="item">
		<div class="image">
			<img src="">
		</div>
		<div class="information">
			<p> Name: </p> <p> </p>
			<p> Model: </p> <p> </p>
			<p> Price: </p> <p> </p>
		</div>
	</div>

	<hr class="solid">

	<div class="item">
		<div class="image">
			<img src="">
		</div>
		<div class="information">
			<p> Name: </p> <p> </p>
			<p> Model: </p> <p> </p>
			<p> Price: </p> <p> </p>
		</div>
	</div>

</div>


<?php
include 'footer.php';
?>
