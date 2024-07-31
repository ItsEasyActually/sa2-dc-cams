# SA2 Dreamcast Cameras

Dreamcast Cameras brings the Dreamcast Camera files to SA2PC. This project is a small detour from a larger project involving creating a tool for editing cameras in both Sonic Adventure DX and Sonic Adventure 2. 

You can download the mod [here](https://github.com/ItsEasyActually/sa2-dc-cams/releases/download/v1.00/DreamcastCameras.7z).

This mod comes bundled with prototype versions of the cameras where applicable. This repository stores the code used to handle the configuration and file swapping for that.

Please be advised that there is no comprehensive list of changes, and during research, most of the time the only changes from DC to Battle were the inclusion of a couple of additional cameras/collisions in levels.

## Notes
- This mod is provided as is. I've done as much testing as I can with some assistance from a couple of friends. 
- Some levels may be buggy with the earlier versions of the camera files. A list of stuff that was found can be seen below.
- Configuration Options are explained as such:
	- Final: Final Dreamcast Version (June 23, 2001)
	- The Trial: First preview of the game released, only City Escape data included (November 15, 2000)
	- Preview: Early preview of the game. (March 18, 2001)
	- Trial Version: Another early version of the game. (May 3, 2001)
	- Prototype: A very late debugging prototype of the game. (May 7, 2001)
	- Review: A review build dated a few weeks prior to release. (May 21, 2001)
	- Disable: This disables the level and uses the cam data found on PC.

## Level Info
- Pumpkin Hill
	- This level has the most notable changes to Battle with several cameras included in the layout that are missing in Battle (Final and protos seem to include the changes). It arguably makes a few of the areas where the camera gets weird much better.
- City Escape:
	- The Trial camera file will not allow you to complete Mission 3/Lost Chao. The camera sets itself on the ground and will not move when climbing the building.
- Final Rush
	- Just like City Escape, the Prototype version of this level's camera will bug out when trying to complete Mission 3/Lost Chao. It sets the camera's position way outside of where the player is. Unlike City Escape, this one will likely result in taking a death. 