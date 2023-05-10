# Important notes :
* ***THIS REPO CONTAINS NO FUNCTIONING MALWARE.*** The code included is an early prototype that has been modified for simplicity and understandability at the intentional cost of functionality. It has been included for demonstrative purposes so that my explanations can make more sense.
* This project is named "umount" because originally all I wanted the malware to do was unmount a file system, but it turned into something more malicious as I worked on it.

## What is this repo about?
This repo is for a simple malware that I wanted to use to both test out my Raspberry Pi while also doing some malware development.

## What does it model?
If a malicious actor was to make use of this code, the attack would look something like the following:
* An unsuspecting user would plug in a USB stick or other storage device into the Raspberry Pi.
* The statfs loop would detect the file system and break out of the infinite loop.
* The contents of the connected file system would be copied to some other location, likely a server owned by the attacking party.
* The file system would be demounted and corrupted, rendering the data irretrievable. 

## How does the code work?
statfs continually searches for connected file systems. If it finds one, the return value of the statfs call will change, prompting the data harvesting to begin. All the files would be copied over (although I personally never got it to save files to a server, only physically connected locations), and the file system destroyed.

## Why create a demonstration of this methodology at all? Is this practical?
Yes, this is a practical, real-world scenario. What I had in mind while creating this was a variant of those malware phone charging stations at malls or airports - https://twitter.com/FBIDenver/status/1643947117650538498?s=20. An example for this malware would be the following: The hacker would go to a public location, for example a library. They would place the device next to public computers or other machines used by customers and put up signs that say something akin to "Please plug in any external devices to this USB hub". In this manner, the hacker would begin to passively harvest data from victims. (It would probably be in the hacker's best interest to not actually unmount the file system to avoid drawing attention, but given that was the entire original purpose of the project I wanted to leave that in my code.) Furthermore, for these types of hacks, since, unlike a virus, there is no propagation required, chances of discovery after the initial deployment are very low. However, there are of course trade-offs. The chances of discovery in the initial phase are extremely high - employees finding a bunch of foreign signs and devices would probably be a matter of concern for most businesses. Thus, the cost of the hardware would need to be extremely cheap given the high rate of loss. Furthermore, unlike a phone, a USB stick may or may not have any data of interest. While some people will plug in their phones or laptops, most people use public computers for simple, low-security matters. Additionally, the real world is much easier to survey and track than the digital world. Actual deployment would probably need to be done through hiring a middleman for a few hundred dollars, compounding the cost issue even further. This middleman would also have to be given the devices in some form, compromising the attacker even further. (Although charging station attacks have these same issues and have been done.) Thus, while this is a practical attack, opportunity cost means something like this would never be deployed in the real world. 
