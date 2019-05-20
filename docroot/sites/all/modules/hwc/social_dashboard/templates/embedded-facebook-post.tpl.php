<?php

$id_parts = explode('_', $content['social_id']);
$data_href = "https://www.facebook.com/" . $id_parts[0] . "/posts/" . $id_parts[1] . "/";
echo "<div data-width=\"auto\" class=\"fb-post\" data-href=\"{$data_href}\"></div>";
