# invoke SourceDir generated makefile for empty.pem4f
empty.pem4f: .libraries,empty.pem4f
.libraries,empty.pem4f: package/cfg/empty_pem4f.xdl
	$(MAKE) -f /home/birdman/workspace_v6_1/googleStillSucks/src/makefile.libs

clean::
	$(MAKE) -f /home/birdman/workspace_v6_1/googleStillSucks/src/makefile.libs clean

