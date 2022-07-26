<?php
include 'header.php';
?>

  <!-- adding a bootstrap container to keep carousel inside -->
  <div class="carousel">
    <!-- carousel class that contains image slideshow to showcase projects it will shuffle through 7 slides-->
    <div class="slideshow-container">
      <!-- Each seperate div is a slide in the slideshow that will be randomly flipped through ysung java script -->
      <div class="mySlides">
        <img src="https://image.ebuyer.com/customer/promos/banners20/hpb/BD1074-amd-q4-alpha-hpb.jpg" alt="placeholder">
      </div>

      <div class="mySlides">
        <img src="https://image.ebuyer.com/customer/promos/banners20/hpb/BD1074-amd-q4-alpha-hpb.jpg" alt="placeholder">
      </div>

      <div class="mySlides">
        <img src="https://image.ebuyer.com/customer/promos/banners20/hpb/BD1074-amd-q4-alpha-hpb.jpg" alt="placeholder">
      </div>
    </div>
  </div>

    <!-- wrote this as part of a website building project for first year -->
  <script>
    var slideIndex = 0;
    showSlides();
    myFunction();

    function showSlides() {
      var i;
      var slides = document.getElementsByClassName("mySlides");
      for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
      }
      slideIndex++;
      if (slideIndex > slides.length) {
        slideIndex = 1
      }
      slides[slideIndex - 1].style.display = "block";
      setTimeout(showSlides, 10000); // Change image every 5 seconds
    }
  </script>

<?php
include 'footer.php';
?>
