<?php
    require_once './vendor/autoload.php';
    $CONFIG = require_once './config.php';
    $HOST = $_SERVER['HTTP_HOST'];

    Flight::route('GET /', function(){ 

        Flight::render('nav.php', array(), 'nav');
        Flight::render('footer.php', array(), 'footer');
        Flight::render('index.php', array(), 'content');
        Flight::render('skeleton.php', array());
    });

    Flight::route('GET /index.html', function(){
        Flight::redirect('/');
    });

    Flight::route('GET /index.php', function(){
        Flight::redirect('/');
    });

    Flight::map('notFound', function(){
        include '404.php';

        Flight::stop(404);
    });

    if( LOCAL == true){
      Flight::view()->set('cdnUrl', 'http://localhost/dashboard/cdn/');
       Flight::view()->set('imgUrl', 'http://localhost/dashboard/cdn/images/');
    }
    else{
      Flight::view()->set('cdnUrl', '');
     Flight::view()->set('imgUrl', '');
   }
    Flight::view()->set('HOST', $HOST);

    Flight::view()->set('debug', DEBUG);
    Flight::start();
