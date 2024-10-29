import json
import requests

def main():
    name_lst = ["bun_ny_1_", 'hiccup.01._', 'perks.of.being.jeevika']
    name = "jagdamba_enterprises1"
    name2 = 'a'
    #get user id
    url1 = "https://i.instagram.com/api/v1/users/web_profile_info/?username="+name2
    url2 = "https://www.instagram.com/web/search/topsearch/?query="+name_lst[1]; #working
    url3 = "https://www.instagram.com/"+name+"/?__a=1"
    url4 = "https://www.instagram.com/"+name+"/?_a=1"
    #user id to tag search
    uid = '17841405309211844'
    tag = 'coke'
    tagid = ''
    trl1 = "http://graph.facebook.com/ig_hashtag_search?user_id="+uid+"&q="+tag;  #working
    get_profile_data(name_lst)


    #tag search api
    #trl2 = ""
    #responses = requests.get(url2).json()
    #print(json.dumps(responses, indent=2))

    
    '''curl -s 'https://i.instagram.com/api/v1/users/web_profile_info/?username=seeker_1002' -H 'X-IG-App-ID: 936619743392459' | jq -r .data.user.id
    '''

def get_profile_data(names):
    url = "https://www.instagram.com/web/search/topsearch/?query="+names[2]; #working
    responses = requests.get(url).json()
    for position in responses['users']:
        if position['user']['username'] == names[2]:
            print(json.dumps(position['user'], indent=2))

def get_post_data(link):
    responses = str(requests.get(link).content)
    for name in responses.split("href=")[1:]:
        print(name.split(" ")[0])


get_post_data("https://www.instagram.com/p/CramXRGPRkD/liked_by/")