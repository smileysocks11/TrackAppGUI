import requests
from bs4 import BeautifulSoup
import re

# opens file
file = open('C:\\track_data\\raw-athletes.txt', 'w')

url = "https://ks.milesplit.com/meets/529934-eisenhower-high-school-participation-meet-2023/entries#.ZC25jHbMLIU"
page = requests.get(url)

soup = BeautifulSoup(page.content, "html.parser")

# loops until it finds the table number of desired event
num_table = 0
results = soup.select("table")[num_table]

while results.find(string=re.compile("Boys Javelin")) == None:
    num_table += 1
    results = soup.select("table")[num_table]

# finds all of the info from the table as elements
elements = results.find_all("td")

count = 0
# loops through all of the elements
for element in elements:
    # converts the element to a string
    text = element.text.strip()
    # removes the last trivial element
    if "Back to Top" in text:
        del element
    else:
        # checks if the data is a name
        if ',' in text:
            if count != 0:
                # adds the name to the file
                file.write('\n' + text)
            else:
                # doesn't add a new line if it's the first entry in the file
                file.write(text)
        elif '' == text:
            file.write('#' + '-1')
        else:
            # adds the data to the file
            file.write('#' + text)
            
        count += 1
file.close()


