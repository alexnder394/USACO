/**
* Source: Wikibooks
* Usage: https://open.kattis.com/problems/convexhull
*/

ll cross(pi O, pi A, pi B) {
    return (ll)(A.f-O.f)*(B.s-O.s)
            -(ll)(A.s-O.s)*(B.f-O.f);
}

vpi convex_hull(vpi P) {
    sort(all(P)); P.erase(unique(all(P)),P.end());
    if (P.size() == 1) return P;
    
    int n = P.size();
    
    vpi bot = {P[0]};
    FOR(i,1,n) {
        while (bot.size() > 1 && cross(bot[sz(bot)-2], bot.back(), P[i]) <= 0) bot.pop_back();
        bot.pb(P[i]);
    }
    bot.pop_back();
    
    vpi up = {P[n-1]};
    F0Rd(i,n-1) {
        while (up.size() > 1 && cross(up[sz(up)-2], up.back(), P[i]) <= 0) up.pop_back();
        up.pb(P[i]);
    }
    up.pop_back();
    
    bot.insert(bot.end(),all(up));
    return bot;
}
