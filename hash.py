
vote_hash = {}
'''
used to avoid repeating
'''
def vote(name):
    if vote_hash.get(name) :
        print "already voted"
    else:
        vote_hash[name] = True;
        print "begin to vote"

cache_hash = {}


'''
demonstrate how to cache web content 
'''
def get_page(url):
    if cache_hash.get(url):
        return cache_hash["url"]
    else:
        context = get_page_content(url)
        cache_hase[url] = context
        return context


if __name__ == '__main__':
    vote("Zhang")  
    vote("Zhang")  
