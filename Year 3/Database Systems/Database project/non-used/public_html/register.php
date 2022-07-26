<?php
include 'header.php';
?>
<form action="signup.php" style="border:1px solid #ccc">
  <div class="container">
    
    <h1>Sign Up</h1>
    <p>Please fill in this form to create an account.</p>
    <hr>
    
    <div class = "containerLoginForm">
    
    <div class = "row"><div class = "col-9"><label for="email"><b>Email</b></label></div> <div class = "col"><input type="text" placeholder="Enter Email" name="email" required></div></div>
    
    
    <div class = "row"><div class = "col-9"><label for = "password"><b>Enter Password</b></label></div> <div class = "col"> <input type="password" placeholder="Enter Password" name="psw" required></div></div>
    
    
    <div class = "row"><div class = "col-9"><label for "repeatpassword"><b>Repeat Password</b></label></div><div class = "col"> <input type="password" placeholder="Repeat Password" name="psw-repeat" required></div>
        </div>
    </div>
  

    <p style="text-align:center">By creating an account you agree to our <a href="indexTest.php" style="color:pink">Terms & Privacy</a>.</p>

    <div class="clearfix">
      <button type="button" class="cancelbtn">Cancel</button>
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
