#!/usr/bin/awk -f

# Copyright (c) 2020 Yubico AB. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.
# SPDX-License-Identifier: BSD-2-Clause

NR == 1 {
	print "# Copyright (c) 2020 Yubico AB. All rights reserved."
	print "#"
	print "# Redistribution and use in source and binary forms, with or without"
	print "# modification, are permitted provided that the following conditions are"
	print "# met:"
	print "# "
	print "#    1. Redistributions of source code must retain the above copyright"
	print "#       notice, this list of conditions and the following disclaimer."
	print "#    2. Redistributions in binary form must reproduce the above copyright"
	print "#       notice, this list of conditions and the following disclaimer in"
	print "#       the documentation and/or other materials provided with the"
	print "#       distribution."
	print "# "
	print "# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS"
	print "# \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT"
	print "# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR"
	print "# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT"
	print "# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,"
	print "# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT"
	print "# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,"
	print "# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY"
	print "# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT"
	print "# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE"
	print "# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
	print "#"
	print "# SPDX-License-Identifier: BSD-2-Clause"
	print ""
	print "# This file is automatically generated, and should"
	print "# be used with udev 188 or newer."
	print ""
	print "ACTION!=\"add|change\", GOTO=\"fido_end\""

	next
}

$1 == "vendor" {
	sub("0x", "", $3)
	vendors[$2, "id"] = $3

	f = 4
	while (f <= NF) {
		vendors[$2, "name"] = vendors[$2, "name"] " " $f
		f++
	}
}

$1 == "product" {
	sub("0x", "", $3)
	name = ""

	f = 4
	while (f <= NF) {
		name = name " " $f
		f++
	}

	line = "\n#" name " by" vendors[$2, "name"]"\n"
	line = line"KERNEL==\"hidraw*\""
	line = line", SUBSYSTEM==\"hidraw\""
	line = line", ATTRS{idVendor}==\""vendors[$2, "id"]"\""
	line = line", ATTRS{idProduct}==\""$3"\""
	line = line", TAG+=\"uaccess\""
	line = line", GROUP=\"plugdev\""
	line = line", MODE=\"0660\""

	print line
}

END {
	print "\nLABEL=\"fido_end\""
}
