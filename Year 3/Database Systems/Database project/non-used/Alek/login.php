<?php
include 'header.php';
?>

<div id="login">
        <div class="login">
            <div class="container">
                <div id="login-row" class="row justify-content-center align-items-center">
                    <div id="login-column" class="col-md-6">
                        <div id="login-box" class="col-md-12">
                            <form id="login-form" class="form" action="" method="post">
                                <h3 class="text-center text-info">Welcome back!</h3>
                                <div class="form-group">
                                    <label for="username" class="text-info">E-mail</label><br>
                                    <input type="text" name="username" id="username" class="form-control">
                                </div>
                                    <div class="form-group">
                                    <label for="password" class="text-info">Password</label><br>
                                    <input type="password" name="password" id="password" class="form-control">
                                </div>
                                 <div class="form-group">
                                <div class = "row"><div class="remember-me">
                                            </label><label for="remember-me" class="text-info"><span>Remember me </span><span><input id="remember-me" name="remember-me" type="checkbox"></span>
                                        </div></div>
                                   
                                        
                                        <div class = "row"> <div class = "col-10">
                                            <input type="submit" name="Submit" class="btn btn-info btn-md" value="Submit">
                                        </div>
    
                                    
                                <div id="col">
                                    <div class = "signup"><a href="register.php" style="text-align:center" class="sign-up">Sign up</a></div>
                                    
                                </div>
                                </div>
                                </div>
                                       
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

<?php
//some sort of return login queries etc/???
?>

<?php
include 'footer.php';
?>
