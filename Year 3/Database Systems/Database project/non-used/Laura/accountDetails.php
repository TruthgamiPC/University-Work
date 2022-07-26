<head>
    <link rel="stylesheet" href="bootstrap.css">
</head>


<style>
	#center {
		display: inline-block;
		background-color:rgba(121, 189, 143, 0.3);
		width: 1000px;
		padding: 20px;
		margin: 50px 5% 50px 5%;
	}

	h3 {
	  text-transform: uppercase;
	  color: black;
	}


	#submit {
		margin-top: 20px;
		height: 50px;
	}

	#center > form > input {
		width: 100%;
		margin-top:5px;
		margin-bottom:5px;
	}

	#center > form > label {
		margin-top:5px;
		margin-bottom:5px;
	}




</style>

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


<div id="center">
	<form>
		<h3> Account Details </h3>

		<label for="firstLine">First Address line: </label>
		<input type="text" id="firstLine" name="firstLine" value="" > <br>

		<label for="secondLine">Second Address Line: </label>
		<input type="text" id="secondLine" name="secondLine" value=""> <br>

		<label for="city">City/Town: </label>
		<input type="text" id="city" name="city" value=""> <br>

		<label for="postcode">Postcode: </label>
		<input type="text" id="postcode" name="postcode" value=""> <br>

		<label for="number">Phone Number: </label>
		<input type="text" id="number" name="number" value=""> <br>

		<input id="submit" type="submit" value="Submit">
	</form>

</div>







<?php
include 'footer.php';
?>
