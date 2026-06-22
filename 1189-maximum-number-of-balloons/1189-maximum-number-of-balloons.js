/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    let n = text.length;
    let mp = new Map();
    let sett = new Set(['b', 'a', 'l', 'o', 'n']);

    for(let i = 0; i < n; i++){
        if(sett.has(text[i])) {
            mp.set(text[i], (mp.get(text[i]) || 0) + 1)
        }
    }
        
    let s = "balloon"
    let m = text.length/s.length

    let ans = 0
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < s.length; j++) {
            if(mp.has(s[j])) {
                mp.set(s[j], mp.get(s[j]) - 1);
                if(mp.get(s[j]) === 0)
                    mp.delete(s[j]);
            }
            else 
                return ans
        }
        ans++;
    }
    return ans
};