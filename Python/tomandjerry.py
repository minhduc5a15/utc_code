rengar, twitch, yuumi = map(int, input().split())
print("CAT_A" if abs(rengar - twitch) < abs(twitch - yuumi) else "CAT_B" if abs(rengar - twitch) > abs(twitch - yuumi) else "The mouse has escaped" )
