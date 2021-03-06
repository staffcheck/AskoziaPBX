<?php
/*
	$Id$
	part of AskoziaPBX (http://askozia.com/pbx)
	
	Copyright (C) 2007-2008 tecema (a.k.a IKT) <http://www.tecema.de>.
	All rights reserved.
	
	Askozia®PBX is a registered trademark of tecema. Any unauthorized use of
	this trademark is prohibited by law and international treaties.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	1. Redistributions of source code must retain the above copyright notice,
	   this list of conditions and the following disclaimer.
	
	2. Redistributions in binary form must reproduce the above copyright
	   notice, this list of conditions and the following disclaimer in the
	   documentation and/or other materials provided with the distribution.
	
	3. Redistribution in any form at a charge, that in whole or in part
	   contains or is derived from the software, including but not limited to
	   value added products, is prohibited without prior written consent of
	   tecema.
	
	THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
	AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
	OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/

require_once("functions.inc");

/**
 * Returns all callgroups sorted by name.
 * If no callgroups are defined, the global array is initialized.
 * This should be changed to return by reference to eliminate a lot of repetitive code.
 */
function callgroups_get_groups() {
	global $config;
	
	if (!is_array($config['dialplan']['callgroup']))
		$config['dialplan']['callgroup'] = array();
		
	callgroups_sort_groups();
		
	return $config['dialplan']['callgroup'];
}

/**
 * Sorts callgroups by name
 */
function callgroups_sort_groups() {
	global $config;

	usort($config['dialplan']['callgroup'], "pbx_sort_by_name");	
}

/**
 * Returns a specific callgroup based on its uniqid
 */
function callgroups_get_group($uniqid) {
	global $config, $uniqid_map;

	return $config['dialplan']['callgroup'][$uniqid_map[$uniqid]];
}

/**
 * Returns an array of all assigned callgroup extensions
 * XXX : an isset check may be missing here on 'extension'
 */
function callgroups_get_extensions() {
	global $config;
	
	$extensions = array();

	if (is_array($config['dialplan']['callgroup'])) {
		foreach($config['dialplan']['callgroup'] as $group) {
			$extensions[$group['uniqid']] = $group['extension'];
		}
	}

	return $extensions;
}

?>
