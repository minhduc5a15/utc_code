from datetime import datetime as dt

print(abs(dt.strptime(input(), "%d %m %Y") - dt.strptime(input(), "%d %m %Y")).days)
