/* Note: These headers were borrowed from the default scalpel configuration file. */

// File Type Headers. Format: {start, end}
unsigned char *fileTypes[][2] = {
	{"\x4a\x47\x04\x0e", "\xcf\xc7\xcb"}, // ART
	{"\x47\x49\x46\x38\x37\x61", "\x00\x3b"}, // GIF
	{"\xff\xd8\xff\xe0\x00\x10", "\xff\xd9"}, // JPG
	{"\x50\x4e\x47\x18", "\xff\xfc\xfd\xfe"}, // PNG
	{"\x00\x00\x01\xba", "\x00\x00\x01\xb9"}, // MPG
	{"\x00\x00\x01\xb3", "\x00\x00\x01\xb7"}, // MPG
	{"\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1\x00\x00", "\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1\x00\x00"}, // DOC
	{"\x21\x42\x4e\xa5\x6f\xb5\xa6", ""}, // PST
	{"\x21\x42\x44\x4e", ""}, // OST
	{"\xcf\xad\x12\xfe\xc5\xfd\x74\x6f", ""}, // DBX
	{"\x4a\x4d\x46\x39", ""}, // IDX
	{"\x4a\x4d\x46\x36", ""}, // MBX
	{"<html>", "</html>"}, // HTML
	{"%!PS-Adobe", "%EOF\x0a"}, // PS
	{"%PDF", "%EOF\x0d"}, // PDF
	{"%PDF", "%EOF\x0a"}, // PDF
	{"-----BEGIN RSA PRIVATE KEY-----", "-----END RSA PRIVATE KEY-----"}, // Private key
	{"-----BEGIN OPENSSH PRIVATE KEY-----", "-----END OPENSSH PRIVATE KEY-----"}, // Private key
	{"PK\x03\x04", "\x3c\xac"}, // ZIP
};

// File Type Options. Format: {startLength, endLength, asciiOnly (true/false)}
unsigned char fileTypeOptions[][3] = {
	{4, 3, 0}, // ART
	{6, 2, 0}, // GIF
	{6, 2, 0}, // JPG
	{4, 4, 0}, // PNG
	{4, 4, 0}, // MPG
	{4, 4, 0}, // MPG
	{10, 10, 0}, // DOC
	{7, 0, 0}, // PST
	{4, 0, 0}, // OST
	{8, 0, 0}, // DBX
	{4, 0, 0}, // IDX
	{4, 0, 0}, // MBX
	{6, 7, 1}, // HTML
	{10, 5, 1}, // PS
	{4, 5, 1}, // PDF
	{4, 5, 1}, // PDF
	{31, 29, 1}, // Private Key
	{35, 33, 1}, // Private Key
	{4, 2, 0}, // ZIP
};

unsigned int numberOfFileTypes = sizeof(fileTypes)/16;