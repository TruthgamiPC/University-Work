<?php
include 'header.php';
?>
<form action="signup.php" style="border:1px solid #ccc top-margin:100px margin-bottom:100px">

<div class = "containerTopBottom">
  <div class="container">

    <h1>Sign Up</h1>
    <p>Please fill in this form to create an account.</p>
    <hr>

    <div class = "containerLoginForm">

    <div class = "row"><div class = "col-9"><label for="email"><b>Email</b></label></div> <div class = "col"><input type="text" placeholder="Enter Email" name="email" required></div></div>


    <div class = "row"><div class = "col-9"><label for = "password"><b>Enter Password</b></label></div> <div class = "col"> <input type="password" placeholder="Enter Password" name="psw" required></div></div>


    <div class = "row"><div class = "col-9"><label for "repeatpassword"><b>Repeat Password</b></label></div><div class = "col"> <input type="password" placeholder="Repeat Password" name="psw-repeat" required></div>
        </div>


    <!-- title here -->
    <div class = "row"><div class = "col-9"><label for "title"><b>Title</b></label></div>
      <div class = "col"> <select name="title">
      <option value ="Mr">Mr</option>
      <option value ="Mrs">Mrs</option>
      <option value ="Miss">Miss</option>
      <option value ="Master">Master</option>
      <option value ="PC Master Racer">PC Master Racer</option>
      </select>
      </div>
    </div>

    <div class = "row"><div class = "col-9"><label for="firstname"><b>First Name</b></label></div> <div class = "col"><input type="text" placeholder="First Name" name="firstname" required></div></div>

    <div class = "row"><div class = "col-9"><label for="lastname"><b>Last Name</b></label></div> <div class = "col"><input type="text" placeholder="Last Name" name="lastname" required></div></div>

    <div class = "row"><div class = "col-9"><label for="phone"><b>Phone Number</b></label></div> <div class = "col"><input type="text" placeholder="Phone Number" name="phone" required></div></div>

    <div class = "row"><div class = "col-9"><label for="address1"><b>Address Line 1</b></label></div> <div class = "col"><input type="text" placeholder="Address Line 2" name="address1" required></div></div>
    <div class = "row"><div class = "col-9"><label for="address2"><b>Address Line 2</b></label></div> <div class = "col"><input type="text" placeholder="Address Line 2" name="address2" required></div></div>
    <div class = "row"><div class = "col-9"><label for="city"><b>City/Town</b></label></div> <div class = "col"><input type="text" placeholder="City/Town" name="city" required></div></div>

    <div class = "row"><div class = "col-9"><label for="country"><b>Country</b></label></div> <div class = "col"><input type="text" placeholder="Country" name="country" required></div></div>

    <div class = "row"><div class = "col-9"><label for="postcode"><b>Postcode</b></label></div> <div class = "col"><input type="text" placeholder="Postcode" name="postcode" required></div></div>


    </div>



    <p style="text-align:center">By creating an account you agree to our <a href="indexTest.php" style="color:blue">Terms & Conditions</a>.</p>

    <div class="clearfix">
      <button type="submit" class="signupbtn">Sign Up</button></div>

    </div>
  </div>
</form>

<?php
//some sort of return login queries etc/???
?>

<?php
include 'footer.php';
?>
