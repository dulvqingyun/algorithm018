    def getHint(self, secret: str, guess: str) -> str:
        if len(secret)!=len(guess):
            return null
        x=0
        y=0
        dg=dict()
        ds=dict()
        for s,g in zip(secret,guess):
            if s==g:
                x+=1
            else:
                dg[g]= dg.get(g,0)+1
                ds[s]= ds.get(s,0)+1
        for k,v in ds.items():
            y+=min(dg.get(k,0),v)
        return "{}A{}B".format(x,y)