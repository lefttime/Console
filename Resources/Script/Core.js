var app = function() {
	this.version = "Console 1.0";
	this.uname	 = "Win64VC9";
	this.arch	 = "arch-Win64VC9-Optimize";
	this.hostid  = "648099399c0d d067e5330f32 648099399c0c c0f8dae8f84e 005056c00001 005056c00008"
	this.listen  = function() {}
	this.close   = function() {}
	this.port    = 7175;
	this.send    = function() {}
	this.opengl  = function() {}
	this.cluster = "single"

	this.property = function( name ) {
		return this.version;
	}
}

print( app.version );