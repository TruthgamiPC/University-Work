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
                                <h3 class="text-center text-info">Employee Login</h3>
                                <div class="form-group">
                                    <label for="username" class="text-info">Username</label><br>
                                    <input type="text" name="username" id="username" class="form-control">
                                </div>
                                    <div class="form-group">
                                    <label for="password" class="text-info">Password</label><br>
                                    <input type="password" name="password" id="password" class="form-control">
                                </div>
                                 <div class="form-group">
                                        <div class = "row"> <div class = "col">
                                            <input type="submit" name="Submit" class="btn btn-info btn-md" value="Submit">
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
