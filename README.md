## HackMe
This is a pretty simple program simulating a game and its HP, attempt to hack it.
### This is the anticheat
```cpp
	for(int i{0}; i < usedHP.size(); ++i)
	{
		if (BASE_HP == usedHP[i])
			return false;
	}

	if (HP - HP_DIFFERENCE != BASE_HP || BASE_HP > 100 || BASE_HP < 0)
		return false;

	return true;
```
