<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">
    <meta name="description" content="">
    <meta name="keywords" content="hadashi">
    <meta name="author" content="hadashi">

    <title>Future is here</title>

    <!-- Favicon -->
    <link rel="apple-touch-icon" sizes="57x57" href="<?php echo $imgUrl ?>fav/apple-icon-57x57.png">
    <link rel="apple-touch-icon" sizes="60x60" href="<?php echo $imgUrl ?>fav/apple-icon-60x60.png">
    <link rel="apple-touch-icon" sizes="72x72" href="<?php echo $imgUrl ?>fav/apple-icon-72x72.png">
    <link rel="apple-touch-icon" sizes="76x76" href="<?php echo $imgUrl ?>fav/apple-icon-76x76.png">
    <link rel="apple-touch-icon" sizes="114x114" href="<?php echo $imgUrl ?>fav/apple-icon-114x114.png">
    <link rel="apple-touch-icon" sizes="120x120" href="<?php echo $imgUrl ?>fav/apple-icon-120x120.png">
    <link rel="apple-touch-icon" sizes="144x144" href="<?php echo $imgUrl ?>fav/apple-icon-144x144.png">
    <link rel="apple-touch-icon" sizes="152x152" href="<?php echo $imgUrl ?>fav/apple-icon-152x152.png">
    <link rel="apple-touch-icon" sizes="180x180" href="<?php echo $imgUrl ?>fav/apple-icon-180x180.png">
    <link rel="icon" type="image/png" sizes="192x192"  href="<?php echo $imgUrl ?>fav/android-icon-192x192.png">
    <link rel="icon" type="image/png" sizes="32x32" href="<?php echo $imgUrl ?>fav/favicon-32x32.png">
    <link rel="icon" type="image/png" sizes="96x96" href="<?php echo $imgUrl ?>fav/favicon-96x96.png">
    <link rel="icon" type="image/png" sizes="16x16" href="<?php echo $imgUrl ?>fav/favicon-16x16.png">
    <!-- /Favicon -->

        <?php require_once('font.html');?>


        <link href="<?php echo $cdnUrl ?>stylesheets/style.css" rel="stylesheet" type="text/css" />
        <link href="<?php echo $cdnUrl ?>stylesheets/swiper.min.css" media="screen, projection, print" rel="stylesheet" type="text/css">
        <link href="<?php echo $cdnUrl ?>stylesheets/aos.css" media="screen, projection, print" rel="stylesheet" type="text/css">

  </head>

  <body class="fadein" onload="document.body.setAttribute('class','loaded')">
      <?php echo $nav; ?>
      <?php echo $content; ?>
      <?php echo $footer; ?>
  </body>


  <script defer src="https://use.fontawesome.com/releases/v5.0.10/js/all.js" integrity="sha384-slN8GvtUJGnv6ca26v8EzVaR9DC58QEwsIk9q1QXdCU8Yu8ck/tL/5szYlBbqmS+" crossorigin="anonymous"></script>
  <script src="<?php echo $cdnUrl ?>js/jquery-3.2.1.min.js"></script> 
  <script src="<?php echo $cdnUrl ?>js/swiper.min.js"></script>
  <script src="<?php echo $cdnUrl ?>js/jquery.easing.min.js"></script>
  <script src="<?php echo $cdnUrl ?>js/aos.js"></script>
  <script src="<?php echo $cdnUrl ?>js/Chart.bundle.min.js"></script>
  <script src="<?php echo $cdnUrl ?>js/dashboard.js"></script>

  <script>
  AOS.init();

  $(document).ready(function() {

  $(function() {
     $('a.page-scroll').bind('click', function(event) {
         var $anchor = $(this);
         $('html, body').stop().animate({
             scrollTop: $($anchor.attr('href')).offset().top-150
         }, 1500, 'easeInOutExpo');
         event.preventDefault();
     });
 });


    var savingChart = new Chart($("#savings-chart"), {
       type: 'doughnut',
       data: {
       labels: ["Assets", "Expenses"],
       datasets: [{
           label: '# of Votes',
           data: [80, 20],
           backgroundColor: [
               '#ffb42e',
               '#ff3403'
           ]
       }]
   }
   });

   var activityChart = new Chart($("#activity-chart"), {
      type: 'doughnut',
      data: {
      labels: ["Walk", "Run", "Inactive"],
      datasets: [{
          label: '# of Votes',
          data: [4, 3, 6, 11],
          backgroundColor: [
              '#ffb42e',
              '#ff3403',
              '#e3dde1',
              'rgba(227, 221, 225, 0.2)'
          ]
      }]
  }
  });
});

</script>
</body>
</html>
