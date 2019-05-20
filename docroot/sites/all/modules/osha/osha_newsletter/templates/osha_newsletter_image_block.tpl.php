<div id="join_subscribers">
	<?php if($background_image_url != NULL) {
		print theme('image', array(
			'path' => $background_image_url,
			'alt' => 'Join OSHMail subscribers',
		));
	}?>
	<div id="block_newsletter_image_text">
		<?php print $start_text . ' ' . $subscribers_no . ' ' . $end_text?>
	</div>
</div>